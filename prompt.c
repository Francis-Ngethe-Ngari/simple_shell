#include "shell.h"

/**
 * show_prompt- program to display prompt on the terminal.
 *
 * Return: Nothing
 *
 */
void show_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$datageek:~$ ", 13);
}
