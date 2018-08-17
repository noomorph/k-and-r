#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int max);
int strindex(char source[], char pattern[]);

char pattern[] = "ould";

int main() 
{
	char line[MAXLINE];
	int found = 0;
	
	while (getLine(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}

	return found;
}

int getLine(char s[], int lim)
{
	int c, i;
	
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';

	return i;
}

int strindex(char source[], char pattern[])
{
	int i, j, k;

	for (i = 0; source[i] != '\0'; i++) {

		j = i; k = 0;
		while (pattern[k] != '\0' && source[j] == pattern[k]) {
			j++; k++;
		}
		
		if (k > 0 && pattern[k] == '\0')
			return i;
	}

	return -1;
}
