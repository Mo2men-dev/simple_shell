#include "shell.h"

/**
 * add_node - Adds a new node to the beginning of a linked list
 * @head: Pointer to the pointer of the head node
 * @str: String to be stored in the new node
 *
 * Return: Pointer to the new node, or NULL if memory allocation fails
 */
node_t *add_node(node_t **head, char *str)
{
	node_t *new_node = malloc(sizeof(node_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = _strdup(str);

	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

/**
 * free_list - Frees the memory occupied by a linked list
 * @head: Pointer to the head of the linked list
 */
void free_list(node_t *head)
{
	node_t *current = head;
	node_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
}
