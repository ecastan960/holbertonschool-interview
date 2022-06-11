#include "lists.h"
/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to the head of the singly linked list
 * Return: 1 has cycle, else 0.
 **/
int check_cycle(listint_t *list)
{
	listint_t *i = list;
	listint_t *j = list;

	while (i && i->next)
	{
		j = j->next;
		i = i->next->next;
		if (j == i)
			return (1);
	}
	return (0);
}
