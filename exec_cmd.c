#include "shell.h"

/**
 * run_cmd- Function executes a command given by user
 * if valid and also supports arguements.
 *
 * @input: Pointer to char array (string) representing
 * command to be executed.
 *
 * Description: argv char array is declared to store commands
 * and its arguemenets. itr variable is declared and initialized
 * to zero to keep track of the number of command-line arguments.
 *
 * Return: Nothing
 *
 */

void run_cmd(char *input);

void run_cmd(char *input)
{
	char *cmds[INPUT_SIZ];
	int no_cmds = 0;
	int itr = 0;
	char *end;
	char *tokn = strtok(input, ";");
	int result = 1;/*init result to true(1)*/

	while (tokn != NULL && no_cmds < INPUT_SIZ)
	{
		cmds[no_cmds++] = tokn;
		tokn = strtok(NULL, ";");
	}
	while (itr < no_cmds)
	{
		/*Trim leading and trailing whitespaces from the command*/
		char *cmd = cmds[itr];

		while (isspace(*cmd))
			cmd++;
		end = cmd + _strlen(cmd) - 1;
		while (end > cmd && isspace(*end))
			end--;
		end[1] = '\0';

		if (_strlen(cmd) > 0)
		{
			int store_status;
			pid_t chld_pid;
			char *argv[INPUT_SIZ];
			int itr = 0;
			char *tokn = strtok(cmd, " ");

			while (tokn != NULL && itr < INPUT_SIZ - 1)
			{
				argv[itr] = tokn;
				tokn = strtok(NULL, " ");
				itr++;
			}
			argv[itr] = NULL;
			/*Handle logical operators*/
			if (itr > 0)
			{
				if (_strcmp(argv[0], "&&") == 0)
				{
					if (result != 0)
					{
						continue;/*Skip execution of subsequent commands*/
					}
				} else if (_strcmp(argv[0], "||") == 0)
				{
					if (result == 0)
					{
						continue;/*Skip execution of subsequent commands*/
					}
				}
			}

			chld_pid = fork();
			if (chld_pid == 0)
			{
				if (execvp(argv[0], argv) == -1)
				{
					char err_m[128];

					snprintf(err_m, sizeof(err_m), "Command not found: %s\n", argv[0]);
					write(2, err_m, _strlen(err_m));
					exit(1);
				}
			}
			else if (chld_pid < 0)
				perror("Fork failed");
			else
				wait(&store_status);
		}
		itr++;
	}
}
