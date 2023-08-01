#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Double pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current, *temp;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		size++;
		temp = current;
		current = current->next;

		/* Avoid loop and set the next pointer to NULL */
		temp->next = NULL;
		free(temp);

		/* Check if we reach the head again (loop detected) */
		if (current == *h)
		{
			*h = NULL;
			break;
		}
	}

	return (size);
}
