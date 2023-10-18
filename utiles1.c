#include "shell.h"

/**
 * is_interactive - Checks if the shell is running in interactive mode
 *
 * Return: 1 if running interactively, 0 otherwise
 */
int is_interactive(void)
{
	return (isatty(STDIN_FILENO));
}

/**
 * is_alpha - Checks if a character is an alphabetic character
 * @c: Character to be checked
 *
 * Return: 1 if the character is a letter, 0 otherwise
 */
int is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
