#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add_nodeint - Adds a new node at the end of a listing_t list.
 * @head: Double pointer to the head of the linked list.
 * @n: Integer value to be added to the new node.
 *
 * Return: The address of the new element, or NULL if it faails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node, *temp;

	new_node = (listint_t *)malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	}
	return (new_node);
}

