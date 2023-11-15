# include "shell.h"

/**
 * _strcmp - 
 *
 * @str_1:
 * @str_2:
 *
 * Return:
 *
 */

int _strcmp(char *str_1, char *str_2)
{
	while (*str_1 != '\0' && *str_2 != '\0')
	{
		if (*str_1 != *str_2)
			return (*str_1 - *str_2);
	}
	if (*str_1 != '\0')
		return (1);
	else if (*str_2 != '\0')
		return (-1);

	return (0);
}
