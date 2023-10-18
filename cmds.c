#include "shell.h"

/**
 * exec_cmd - Executes a command given an array of arguments.
 * @global: Pointer to the global structure containing shell information.
 * @argv: Array of strings containing the command and its arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int exec_cmd(global_t *global, char **argv)
{
	char *cmd = get_path(global, argv[0]);
	pid_t pid;

	if (cmd == NULL)
	{
		_print_err(global, "not found\n");
		free(cmd);
		return (ERR_STATUS);
	}

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		free(cmd);
		return (1);
	}

	if (pid == 0)
	{
		if (execve(cmd, argv, environ) == -1)
		{
			perror("Error");
			free(cmd);
			return (1);
		}
	}
	else
	{
		wait(NULL);
	}
	free(cmd);
	return (0);
}
