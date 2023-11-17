#include "shell.h"

/**
 * print_env- Function accesses the environ variable
 * which is an array char which contains all env variables
 * hence looping through them one by one.All environment var
 * are displayed on standard output.
 *
 * Return: Nothing.
 *
 */
void print_env(void)
{
	extern char **environ;
	int itr = 0;

	while (environ[itr] != NULL)
	{
		write(STDOUT_FILENO, environ[itr], _strlen(environ[itr]));
		write(STDOUT_FILENO, "\n", 1);
		itr++;
	}
}
