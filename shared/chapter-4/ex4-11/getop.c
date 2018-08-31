# include <stdio.h>
# include <ctype.h>
# include "calc.h"

static char last_char = ' ';

int getop(char buffer[])
{
	register int i;
	register int c = last_char;

	while (c == ' ' || c == '\t') {
		c = buffer[0] = getch();
	}

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
	last_char = c;

	return NUMBER;
}
