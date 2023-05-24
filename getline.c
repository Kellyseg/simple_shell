#include "main.h"

int __fgetc(FILE *stream);
ssize_t _getdelim(char **lineptr, size_t *len, int delimiter, FILE *stream);
/**
 * _fgetc - get char from a file stream
 * @stream: file stream
 * Return: returns the charc
 */
int _fgetc(FILE *stream)
{
	char ch;

	if (read(fileno(stream), &ch, 1) == -1)
		return (EOF);
	return (ch);
}

/**
 * _getdelim - gets line with a delimiter
 * @lineptr: points to the pointer that points to the chars
 * @len: size of lineptr
 * @delimiter: delimiter
 * @stream: file stream to read from
 * Return: something
 */
ssize_t _getdelim(char **lineptr, size_t *len, int delimiter, FILE *stream)
{
	char *begptr, *endptr, *newbuf;
	int ch;
	size_t newlen;
	ssize_t dist;

	if (*lineptr == NULL || *len == 0)
	{
		*len = BUFSIZ;
		*lineptr = malloc(sizeof(char) * *len);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	for (begptr = *lineptr, endptr = *lineptr + *len;;)
	{
		ch = fgetc(stream);
		if (ch == -1)
		{
			if (feof(stream))
			{
				if (begptr == *lineptr)
					return (-1);
				else
					return (begptr - *lineptr);
			}
			else
				return (-1);
		}

		*begptr++ = ch;
		if (ch == delimiter)
		{
			*begptr = '\0';
			return (begptr - *lineptr);
		}
		if (begptr + 2 >= endptr)
		{
			newlen = *len * 2;
			dist = begptr - *lineptr;
			newbuf = realloc(*lineptr, sizeof(char) * newlen);
			if (newbuf == NULL)
				return (-1);
			*lineptr = newbuf;
			*len = newlen;
			endptr = newbuf + newlen;
			begptr = newbuf + dist;
		}
	}
}

/**
 * _getline - gets a line from a stream
 * @lineptr: points to the pointer that points to
 * the chars
 * @len: the size of lineptr
 * @stream: the file stream
 * Return: length of chars retrieved
 */
ssize_t _getline(char **lineptr, size_t *len, FILE *stream)
{
	return (_getdelim(lineptr, len, '\n', stream));
}
