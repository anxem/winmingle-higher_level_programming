#include <stdlib.h>
#include "lists.h"


/**
 * insert_node - insert a number into a sorted singly linked list
 * @head: double pointer to the head of the linked list
 * @number: the integer to store in the new node
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;


    if (head == NULL)
	    return (NULL);

    new = malloc(sizeof(listint_t));
    if (new == NULL)
	    return (NULL);
    new->n = number;

    current = *head;

    /* If the list is empty or the new number belongs at the very beginning */
    if (*head == NULL || (*head)->n >= number)
    {
        new->next = *head;
	*head = new;
	return (new);
    }

    /* Traverse the list to find the correct insertion point */
    while (current->next != NULL && current->next->n < number)
    {
        current = current->next;
    }

    new->next = current->next;
    current->next = new;

    return (new);
}
