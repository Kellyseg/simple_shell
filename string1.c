#include "main.h"

/**
 * _strcpy - copies a string into anotehr
 * @dest: string to be added to
 * @src: string to be copied
 * Return: nothing (void)
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = 0;
	return (dest);
}

/**
 * _strdup - returns pointer to newly allocated
 * space
 * @str: string
 * Return: either NULL or pointer
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @ch: The character to print
 * Return: 1 or -1
 */
int _putchar(char ch)
{
	static int i;
	static char buf[WR_BUF];

	if (ch == BUF_FL || i >= WR_BUF)
	{
		write(1, buf, i);
		i = 0;
	}
	if (ch != BUF_FL)
		buf[i++] = ch;
	return (1);
}
