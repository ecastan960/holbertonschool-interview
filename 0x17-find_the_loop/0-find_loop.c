#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list
 * @head: pointer to head node
 * Return: Location of node where the loop begins or NULL 
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *result = head;
	listint_t *i = head;

	while (i && i->next != NULL)
	{
		result = result->next;
		i = i->next->next;

		if (result == i)
			break;
	}

	if (result != i)
		return (NULL);

	result = head;

	while (result != i)
	{
		result = result->next;
		i = i->next;
	}

	return (result);
}
