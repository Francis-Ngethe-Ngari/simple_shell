#include "shell.h"
/**
 * _getinput - reads a line of text from user,
 * handles CTRL + D instances and returns pointer to char
 * array (string).
 *
 * Description: store_str represents a pointer to char array (string)
 * which will be used to store user's input.
 * store_size represents integer which specifies the limit to how many
 * char's can be stored in the store_str var.
 *
 * Return: Pointer to char array which rep user's input.
 *
 */
char *_getinput(void)
{
	char *store_str = NULL;
	size_t store_size = 0;
	size_t str_leng;

	if (getline(&store_str, &store_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			/*write(STDOUT_FILENO, "\n", 1);*/
			free(store_str);
			return (NULL);
		}
	}
	str_leng = _strlen(store_str);
	if (str_leng > 0 && store_str[str_leng - 1] == '\n')
	{
		store_str[str_leng - 1] = '\0';
	}
	return (store_str);
}
