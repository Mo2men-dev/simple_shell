#include "shell.h"

/**
 * rfctr_e - Converts environment variables to linked list nodes
 * @env: Array of environment variables
 *
 * Return: Pointer to the head of the linked list
 */
node_t *rfctr_e(char **env)
{
	node_t *head = NULL;
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		add_node(&head, env[i]);
	}

	return (head);
}

/**
 * _getenv - Gets the value of a specific environment variable
 * @head: Pointer to the head of the linked list
 * @name: Name of the environment variable to search for
 *
 * Return: Value of the specified environment variable, or NULL if not found
 */
char *_getenv(node_t *head, char *name)
{
	node_t *current = head;
	char *token;
	char *value;
	const char *delim = "=";

	while (current != NULL)
	{
		token = strtok(current->str, delim);
		if (_strcmp(token, name) == 0)
		{
			value = strtok(NULL, delim);
			return (value);
		}
		current = current->next;
	}

	return (NULL);
}

/**
 * add_env - Adds or updates an environment variable in the linked list
 * @head: Pointer to the head of the linked list
 * @name: Name of the environment variable
 * @value: Value of the environment variable
 *
 * Return: 0 on success, -1 on failure
 */
int add_env(node_t **head, char *name, char *value)
{
	node_t *current = *head;
	char *new_env;
	int name_length = _strlen(name);
	int value_length = _strlen(value);

	new_env = malloc(sizeof(char) * (name_length + value_length + 2));
	if (new_env == NULL)
		return (-1);

	_strcpy(new_env, name);
	_strcat(new_env, "=");
	_strcat(new_env, value);
	_strcat(new_env, "\0");

	while (current != NULL)
	{
		if (_strcmp(current->str, name) == 0)
		{
			free(current->str);
			current->str = new_env;
			return (0);
		}
		current = current->next;
	}

	add_node(head, new_env);
	return (0);
}
