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
		if (strcmp(cmd, "exit") == 0)
			exit_cmd();
		else if (strcmp(cmd, "env") == 0)
			print_env();
		run_cmd(cmd);
		free(cmd);
	}
	exit(EXIT_SUCCESS);
}
