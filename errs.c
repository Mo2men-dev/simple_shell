#include "shell.h"

/**
 * _print_err - Prints error message to standard error output
 * @global: Pointer to the global structure
 * @err: Error message to be printed
 */
void _print_err(global_t *global, char *err)
{
	_eputs(global->p_name);
	_eputs(": ");
	print_number(global->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(global->curr_cmd);
	_eputs(": ");
	_eputs(err);
}

/**
 * _eputs - Writes a string to the standard error output
 * @str: String to be written
 */
void _eputs(char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
}

/**
 * print_number - Prints an integer to the specified file descriptor
 * @n: Integer to be printed
 * @fd: File descriptor to which the integer is printed
 *
 * Return: Number of digits in the integer
 */
int print_number(int n, int fd)
{
	int div = 1, len = 0, i = 0;

	if (n < 0)
	{
		n = -n;
		_putchar_fd('-', fd);
		len++;
	}
	while (n / div > 9)
	{
		div *= 10;
	}
	while (div > 0)
	{
		i = n / div;
		_putchar_fd(i + '0', fd);
		len++;
		n -= i * div;
		div /= 10;
	}
	return (len);
}
