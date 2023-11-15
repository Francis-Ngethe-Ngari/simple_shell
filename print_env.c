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
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
