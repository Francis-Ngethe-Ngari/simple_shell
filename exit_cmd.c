#include "shell.h"

/**
 * exit_cmd- Program handles exit
 * when user writes to terminal command 'exit'.
 * Utilizes the inbuilt exit command in shell.
 *
 * Return: Nothing.
 *
 */
void exit_cmd(void)
{
	/*The shell command to handle the exit of the program*/
	const char *sh_cmd = "sh -c 'echo Program is exiting; exit 0'";
	/*Use the system function to execute the shell command*/
	int status = system(sh_cmd);

	if (status == -1)
		perror("Error executing shell command");
	exit(0);
}
