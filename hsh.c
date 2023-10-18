#include "shell.h"

/**
 * hsh - Main function for the custom shell
 * @global: Pointer to the global structure
 * @argv: Command-line arguments passed to the shell
 *
 * Return: Exit status of the shell
 */
int hsh(global_t *global, char **argv)
{
	char *buff, *buff_cpy, *prompt = "$ ", *token;
	size_t b_s = 1024;
	ssize_t c_r;
	const char *delim = " \n";
	int tokens_num = 0, cnt = 0, c_r_i = 0;

	buff = (char *)malloc((b_s + 1) * sizeof(char));
	while (1)
	{
		if (is_interactive())
			_puts(prompt);
		c_r = getline(&buff, &b_s, stdin), c_r_i = 0;
		if (c_r == -1)
		{
			free(buff);
			return (global->status);
		}
		if (only_spaces(buff, c_r_i, c_r) == 1)
			continue;
		buff_cpy = malloc((c_r + 1) * sizeof(char));
		_strcpy(buff_cpy, buff), token = strtok(buff, delim);
		while (token != NULL)
			tokens_num++, token = strtok(NULL, delim);
		tokens_num++, argv = malloc(sizeof(char *) * (tokens_num + 1));
		token = strtok(buff_cpy, delim), cnt = 0;
		while (token != NULL)
		{
			argv[cnt] = malloc(sizeof(char) * (_strlen(token) + 1));
			_strcpy(argv[cnt], token), token = strtok(NULL, delim), cnt++;
		}
		argv[cnt] = NULL, global->status = exec_cmd(global, argv);
		while (cnt >= 0)
			free(argv[cnt]), cnt--;
		free(argv), free(buff_cpy);
	}
	free(buff);
	return (global->status);
}

/**
 * only_spaces - Checks if a string contains only spaces
 * @buff: String to check
 * @c_r_i: Current index of the string
 * @c_r: Current read
 *
 * Return: 1 if the string contains only spaces, 0 otherwise
 */
int only_spaces(char *buff, int c_r_i, int c_r)
{
	int o_s = 1;

	while (c_r > c_r_i)
	{
		if (is_alpha(buff[c_r_i]))
		{
			o_s = 0;
			break;
		}
		c_r_i++;
	}
	return (o_s);
}
