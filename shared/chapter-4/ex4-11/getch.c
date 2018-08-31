# include <stdio.h>

# define BUFSIZE 100
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
