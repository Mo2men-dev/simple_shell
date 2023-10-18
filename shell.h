#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

#define ERR_STATUS 127
#define _PATH_ALT "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"

/**
 * struct node_t - A structure representing a node in a linked list.
 *
 * @str: A pointer to a string stored in the node.
 * @next: A pointer to the next node in the linked list.
*/
typedef struct node_t
{
	char *str;
	struct node_t *next;
} node_t;

<<<<<<< HEAD
=======
/**
 * struct global_struct_t - A struct of global vars for the shell program.
 *
 * @p_name: Pointer to the name of the shell program.
 * @line_count: Integer representing the current line number being processed.
 * @status: Integer representing the exit status of the last executed command.
 * @curr_cmd: Pointer to the str containing the curr command being processed.
*/
>>>>>>> d6c338b2172ff5e393c7a904b6e80235c3445baf
typedef struct global_struct_t
{
	char *p_name;
	int line_count;
	int status;
	char *curr_cmd;
} global_t;

#define GLOBAL_T_INIT {NULL, 1, 0, NULL}

/* errs.c */
void _print_err(global_t *global, char *err);
int print_number(int n, int fd);
void _eputs(char *str);

/* out.c */
int _putchar(char c);
void _puts(char *str);
int _putchar_fd(char c, int fd);

/* lists.c */
node_t *add_node(node_t **head, char *str);
void free_list(node_t *head);

/* env.c */
node_t *rfctr_e(char **env);
char *_getenv(node_t *head, char *name);

/* strings.c */
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
int _strlen(const char *str);
char *_strcat(char *dest, const char *src);

/* strings2.c */
char *_strcpy(char *dest, const char *src);

/* utiles1.c */
int is_interactive(void);
int is_alpha(char c);

void str_helper(char *cmd_path, char *token, char *cmd);
int hsh(global_t *global, char **argv);
int exec_cmd(global_t *global, char **argv);
char *get_path(global_t *global, char *cmd);
int only_spaces(char *buff, int c_r_i, int c_r);

#endif
