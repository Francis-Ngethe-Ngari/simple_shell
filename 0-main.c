#include "shell.h"

/**
 *main- start point of execution of a program.
 *
 * Return: 0.
 *
 */
int main(void)
{
	char *cmd;

	while ((cmd = _getinput()) != NULL)
	{
		show_prompt();
		if (_strcmp(cmd, "exit") == 0)
			exit(0);
		else if (_strcmp(cmd, "env") == 0)
			print_env();
		run_cmd(cmd);
		free(cmd);
	}
	exit(EXIT_SUCCESS);
}
