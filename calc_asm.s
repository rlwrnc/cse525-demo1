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
	subs	r0, r0, r1
	
mod:

ret:
	mov	pc, lr
	.end
