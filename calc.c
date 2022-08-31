#include <stdio.h>

int add(int i1, int i2);
int sub(int i1, int i2);
int mul(int i1, int i2);
int div(int i1, int i2);
int mod(int i1, int i2);

int main()
{
	char input = 0;
	int n[2] = {0, 0};
	
	printf("welcome to calculator (~ to quit)\n\n");
	while (1){
		printf("choose an operation (+, -, or *): ");
		scanf(" %c", &input);
		
		if (input == '~')
			break;
		if (input != '+' && input != '-' && input != '*')
			printf("invalid operation.\n");
		
		for (int i = 0; i < 2; i++) {
			printf("enter an integer: ");
			scanf(" %d", &n[i]);
		}

		if (input == '+') printf("%d + %d = %d\n\n", n[0], n[1], add(n[0], n[1]));
		if (input == '-') printf("%d - %d = %d\n\n", n[0], n[1], sub(n[0], n[1]));
		if (input == '*') printf("%d * %d = %d\n\n", n[0], n[1], mul(n[0], n[1]));
	}
	return 0;
}
