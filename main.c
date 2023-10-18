#include "shell.h"

/**
 * main - Entry point of the shell program
 * @ac: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Exit status of the shell program
 */
int main(int ac, char **argv)
{
	global_t global[] = {GLOBAL_T_INIT};

	global->p_name = argv[0];
	(void)ac;
	global->status = hsh(global, argv);

	return (global->status);
}
