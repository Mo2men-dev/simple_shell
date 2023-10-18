#include "shell.h"

/**
 * _strcpy - Copies a string from source to destination
 * @dest: Destination buffer
 * @src: Source string to be copied
 *
 * Return: Pointer to the destination buffer
 */
char *_strcpy(char *dest, const char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
