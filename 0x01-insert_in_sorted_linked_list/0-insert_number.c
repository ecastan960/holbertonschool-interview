#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Function to insert a node in a SL list.
 * @head: A double pointer that contains the head.
 * @number: number to add in the list.
 *
 * Return: head of new list.
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new = NULL,
    *temp = NULL;

    new = malloc(sizeof(listint_t));
    if (new == NULL || head == NULL)
        return NULL;
    new->n = number;
    new->next = NULL;

    if (*head == NULL)
    {
        new->n = number;
        *head = new;
        return (new);
    }
    temp = *head;
    if (number <= temp->n)
    {
        new->n = number;
        new->next = temp;
        *head = new;
        return (new);
    }
    while (temp->next)
    {
        if (temp->next->n >= number)
            break;
        temp = temp->next;
    }
    new->n = number;
    new->next = temp->next;
    temp->next = new;
    return (new);
}