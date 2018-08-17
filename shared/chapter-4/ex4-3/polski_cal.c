# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <ctype.h>

# define MAXOP 100
# define NUMBER '0'
# define EOL '\n'
# define EOS '\0'

# define MAXSTACKDEPTH 100
# define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

int main()
{
	int type;
	double op1;
	double op2;
	char s[MAXOP];

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
		case EOL:
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("Error: Unknown command %s\n", s);
			break;
		}
	}

	return 0;
}


int stackposition = 0;
double valuestack[MAXSTACKDEPTH];

void push(double value)
{
	if (stackposition < MAXSTACKDEPTH)
		valuestack[stackposition++] = value;
	else
		printf("Error: stack full, can't push %g\n", value);
}

double pop(void)
{
	if (stackposition == 0) {
		printf("Error: stack empty\n");
		return 0.0;
	}

	return valuestack[--stackposition];
}

int getop(char buffer[])
{
	int i, c;

	while ((buffer[0] = c = getch()) == ' ' || c == '\t')
		;

	buffer[1] = EOS;

	if (!isdigit(c) && c != '.')
		return c;
	i = 0;

	if (isdigit(c))
		while (isdigit(buffer[++i] = c = getch()))
			;

	if (c == '.')
		while (isdigit(buffer[++i] = c = getch()))
			;

	buffer[i] = EOS;
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}
char buf[BUFSIZE];
int buffreepos = 0;

int getch(void)
{
	return (buffreepos > 0) ? buf[--buffreepos] : getchar();
}

void ungetch(int c)
{
	if (buffreepos >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[buffreepos++] = c;
}
