#include "lists.h"
#include <stddef.h>
/**
 * palindrome - verifies if singly linked list is palindrome
 * @pointer: pointer to the head of singly linked list
 * @head: head of singly linked list
 *
 * Return: 1 if palindrome, 0 if not
 */

int palindrome(listint_t **pointer, listint_t *head)
{
	int result;

	if (head == NULL)
	{
		return (1);
	}

	result = palindrome(pointer, head->next);
	if (result == 0)
	{
		return (0);
	}

	result = (head->n == (*pointer)->n);

	*pointer = (*pointer)->next;

	return (result);
}
/**
 * is_palindrome - function in C that checks if a singly linked list is a palindrome.
 * @head: pointer to the head of singly linked list
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	if (head == NULL)
	{
		return (0);
	}
	return (palindrome(head, *head));
}
