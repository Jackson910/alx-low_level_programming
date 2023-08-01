#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - Deletes the head node of a linked list.
 * @head: Double pointer to the first element in the linked list.
 *
 * Return: The data inside the element that was deleted,
 * or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	int num;
	listint_t *temp;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	temp = (*head)->next;

	free(*head);
	*head = temp;

	return (num);
}
