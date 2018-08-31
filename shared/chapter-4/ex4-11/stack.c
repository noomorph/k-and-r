# include <stdio.h>
# include "calc.h"

# define MAXSTACKDEPTH 100

static int stackposition = 0;
static double valuestack[MAXSTACKDEPTH];

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

double peek(void)
{
	if (stackposition == 0) {
		printf("Error: stack empty\n");
		return 0.0;
	}

	return valuestack[stackposition - 1];
}
