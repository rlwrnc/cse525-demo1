	.section ".text"
	.global add
	.global sub
	.global mul
	.global div
	.global mod
add:
	add	r0, r0, r1
	mov	pc, lr
sub:
	sub	r0, r0, r1
	mov	pc, lr
mul:
	mul	r0, r0, r1 
	mov	pc, lr
div:
	// r0 = numerator
	// r1 = denominator
	// r2 = quotient reference, r4 = quotient value
	// r3 = remainder reference, r5 = remainder value
	// r6 = loop iterator

	// init values
	mov 	r4, #0
	mov 	r5, #0
	mov 	r6, #32
	mov	r7, #0

	//check signs
	cmp	r0, #0
	orrlt	r7, r7, #1		// if numerator < 0, set flag in mask
	neglt	r0, r0			// if numerator < 0, make it positive
	
	cmp	r1, #0
	orrlt	r7, r7, #2              // if denominator < 0, set flag in mask
	neglt	r1, r1			// if denominator < 0, make it positive

	cmp	r7, #0

	cmp	r7, #2

	// division loop
	b	div_loop_check
div_loop:
	movs	r0, r0, LSL #1
	adc	r5, r5, r5
	cmp	r5, r1
	subhs	r5, r5, r1
	adc	r4, r4, r4
div_loop_check:
	subs	r6, r6, #1
	bpl	div_loop

	//reintroduce signs
	teq	r7, #1			// case 1: n > 0 and d < 0
	teqne	r7, #2			// case 2: n < 0 and d > 0
	negeq	r4, r4			// make quotient negative

	tst	r7, #2			// if denominator negative
	negne	r5, r5			// make remainder negative		

	str	r4, [r2]
	str	r5, [r3]
	mov	pc, lr
