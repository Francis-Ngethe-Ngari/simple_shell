#include "shell.h"

/**
 * _strlen- function that return the length of a string.
 *
 * @str: pointer to string to which we must find the length.
 *
 * Return: returns an integer which represents length of
 * a string without null terminator.
 *
 */

int _strlen(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}

	return (count);
}
