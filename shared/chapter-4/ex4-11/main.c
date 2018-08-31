# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "calc.h"

# define MAXOP 100

extern int stackposition;

int main()
{
	int type;
	double op1;
	double op2;
	char s[MAXOP];
	int is_peeking = 0;
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			push(-pop() + pop());
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("Error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			op1 = pop();
			if (op2 == 0.0)
				printf("Error: zero modulus\n");
			else if (floorf(op2) != op2)
				printf("Error: floating modulus\n");
			else if (floorf(op1) != op1)
				printf("Error: floating modulo\n");
			else
				push((int) op1 % (int) op2);
			break;
		case 's':
			push(sin(pop() * M_PI / 180));
			break;
		case '>':
			is_peeking = 1;
			break;
		case EOL:
			if (is_peeking)
				printf("\t%.8g\n", peek());
			else
				printf("\t%.8g\n", pop());
			is_peeking = 0;
			break;
		default:
			printf("Error: Unknown command %s\n", s);
			break;
		}
	}

	return 0;
}
