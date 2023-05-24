#include <stdio.h>
#include <string.h>

/**
 * _strtok - breaks a string into tokens
 * @str: string to break
 * @delim: bytes that delimit tokens in the string
 * Return: value of string
 */

char *_strtok(char *str, const char *delim)
{
	static char *token;
	char *start = (str != NULL) ? str : token;
	char *end;

	if (start == NULL || *start == '\0')
	{
		token = NULL;
		return (NULL);
	}

	end = strpbrk(start, delim);

	if (end != NULL)
	{
		*end = '\0';
		token = end + 1;
	}
	else
	{
		token = NULL;
	}
	return (start);
}

/**
 * main - main function
 * Return:0
 */
int main(void)
{
	char str[] = "Guess what? Uncle Willie is my partner! Hurray, Hurray";
	const char delim[] = ", !?";
	char *token = _strtok(str, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = _strtok(NULL, delim);
	}

	return (0);
}

