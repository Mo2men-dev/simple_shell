#include "shell.h"

/**
 * _strlen - Calculates the length of a string
 * @s: The string to calculate length of
 *
 * Return: Length of the string
 */
int _strlen(const char *s)
{
	int i = 0;

	if (s == NULL)
	{
		return (0);
	}

	while (*s != '\0')
	{
		i++;
		s++;
	}

	return (i);
}

/**
 * _strdup - Duplicates a string in memory
 * @str: The string to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL if memory allocation fails
 */
char *_strdup(const char *str)
{
	char *new_str = malloc(sizeof(char) * (_strlen(str) + 1));
	int i;

	if (new_str == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		new_str[i] = str[i];
	}
	new_str[i] = '\0';

	return (new_str);
}

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: 0 if strings are equal
 */
int _strcmp(const char *s1, const char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (0);
	}

	if (*s1 == *s2)
	{
		return (_strcmp(s1 + 1, s2 + 1));
	}

	return (*s1 - *s2);
}

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the destination string
 */
char *_strcat(char *dest, const char *src)
{
	int destLength = _strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[destLength + i] = src[i];
	}

	dest[destLength + i] = '\0';

	return (dest);
}
