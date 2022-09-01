#include <stdio.h>

int add(int i1, int i2);
int sub(int i1, int i2);
int mul(int i1, int i2);
void div(int i1, int i2, int *quotient, int *remainder);

int main()
{
	char input = 0;
	int valid_op, n[2] = {0, 0}, quotient, remainder;
	
	printf("welcome to calculator ('q' to quit)\n\n");
	while (1){
		do {
			printf("choose an operation (+, -, *, /, or q): ");
			scanf(" %c", &input);
			valid_op = (input != '+' && input != '-' && input != '*' && input !='/' && input != 'q');
			
			if (valid_op)
				printf("invalid operation.\n");
		} while (valid_op);
		
		if (input == 'q')
			break;

		for (int i = 0; i < 2; i++) {
			printf("enter an integer: ");
			scanf(" %d", &n[i]);
		}

		if (input == '+') printf("%d + %d = %d\n\n", n[0], n[1], add(n[0], n[1]));
		if (input == '-') printf("%d - %d = %d\n\n", n[0], n[1], sub(n[0], n[1]));
		if (input == '*') printf("%d * %d = %d\n\n", n[0], n[1], mul(n[0], n[1]));
		if (input == '/') {
			if (n[1] == 0) printf("denominator cannot be zero.\n");
			else {
				quotient = 0, remainder = 0;
				div(n[0], n[1], &quotient, &remainder);
				printf("%d / %d = %d r: %d\n\n", n[0], n[1], quotient, remainder);
			}
		}
	}
	return 0;
}
