# include "shell.h"

/**
 * _strcmp - Compares difference of two strings until find
 * the difference or reaches the end of both strings.
 *
 * @str_1: Pointer to 1st string.
 * @str_2: Pointer to 2nd string
 *
 * Return: 0 if both strings are equal or a positive or negative
 * value based on the difference.
 *
 */

int _strcmp(const char *str_1, char const *str_2)
{
	while (*str_1 != '\0' && *str_2 != '\0')
	{
		if (*str_1 != *str_2)
			return (*str_1 - *str_2);
		str_1++;
		str_2++;
	}
	if (*str_1 != '\0')
		return (1);
	else if (*str_2 != '\0')
		return (-1);

	return (0);
}
