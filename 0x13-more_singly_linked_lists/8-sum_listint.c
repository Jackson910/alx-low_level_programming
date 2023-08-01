#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data.
 * @head: Pointer to the first element in the linked list.
 *
 * Return: Sum of all the data, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	if (head == NULL)
		return (0);

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
