#include "shell.h"

/**
 * _putchar - Writes a character to standard output
 * @c: The character to write
 *
 * Return: On success, 1. On error, -1, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Writes a string to standard output
 * @str: The string to write
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

/**
 * _putchar_fd - Writes a character to a specified file descriptor
 * @c: The character to write
 * @fd: The file descriptor
 *
 * Return: On success, 1. On error, -1, and errno is set appropriately.
 */
int _putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
