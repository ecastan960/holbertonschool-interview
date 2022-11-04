#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Adds a new node at the end
 *
 * @list:param
 * @str: param
 * Return: return
 */
List *add_node_end(List **list, char *str)
{
	List *newNode;
	char *strNode;

	if (!list)
		return (NULL);

	newNode = malloc(sizeof(List));
	if (!newNode)
		return (NULL);

	strNode = strdup(str);
	if (!strNode)
	{
		free(newNode);
		return (NULL);
	}
	newNode->str = strNode;

	if (!*list)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		*list = newNode;
		return (newNode);
	}

	newNode->next = *list;
	newNode->prev = (*list)->prev;

	(*list)->prev = newNode;
	newNode->prev->next = newNode;

	return (newNode);
}
/**
 * add_node_begin - Adds a new node at the beginning
 *
 * @list:param
 * @str: param
 * Return: return
 */
List *add_node_begin(List **list, char *str)
{
	List *newNode;
	char *strNode;

	if (!list)
		return (NULL);

	newNode = malloc(sizeof(List));
	if (!newNode)
		return (NULL);

	strNode = strdup(str);
	if (!strNode)
	{
		free(newNode);
		return (NULL);
	}
	newNode->str = strNode;

	if (*list)
	{
		newNode->next = *list;
		newNode->prev = (*list)->prev;
		(*list)->prev = newNode;
		if (newNode->prev)
			newNode->prev->next = newNode;
	}
	else
	{
		newNode->prev = newNode;
		newNode->next = newNode;
	}

	*list = newNode;

	return (newNode);
}
