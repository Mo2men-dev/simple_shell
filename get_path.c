#include "shell.h"

/**
 * get_path - Finds the full path of a command
 * @global: Pointer to the global structure
 * @cmd: Command to find the path for
 *
 * Return: Pointer to the full path of the command, or NULL if not found
 */
char *get_path(global_t *global, char *cmd)
{
	char *path, *token, *path_cpy, *c_p, *delim = ":";
	int c_l, p_l;
	struct stat st;
	node_t *head = NULL;

	if (cmd == NULL)
		return (NULL);
	global->curr_cmd = cmd, head = rfctr_e(environ), path = _getenv(head, "PATH");
	if (!path)
	{
		if (cmd[0] == '/' || cmd[0] == '.')
			path = _PATH_ALT;
		else
		{
			free_list(head);
			return (NULL);
		}
	}
	path_cpy = malloc(sizeof(char) * (_strlen(path) + 1));
	_strcpy(path_cpy, path), c_l = _strlen(cmd), token = strtok(path_cpy, delim);
	while (token != NULL)
	{
		p_l = _strlen(token), c_p = malloc(sizeof(char) * (p_l + c_l + 2));
		str_helper(c_p, token, cmd);
		if (stat(c_p, &st) == 0)
		{
			free(path_cpy), free_list(head);
			return (c_p);
		}
		else
			free(c_p), token = strtok(NULL, delim);
	}
	free(path_cpy), c_p = malloc(sizeof(char) * (c_l + 1));
	if (stat(cmd, &st) == 0)
	{
		_strcpy(c_p, cmd), free_list(head);
		return (c_p);
	}
	free(c_p), free_list(head);
	return (NULL);
}

/**
 * str_helper - Helper function to get_path
 * @c_p: Pointer to the string to be modified
 * @token: Pointer to the token
 * @cmd: Pointer to the command
 */
void str_helper(char *c_p, char *token, char *cmd)
{
	_strcpy(c_p, token);
	_strcat(c_p, "/");
	_strcat(c_p, cmd);
	_strcat(c_p, "\0");
}
