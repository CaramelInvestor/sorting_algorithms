#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a doubly linked
 * list of integers in ascending order using Insertion Sort.
 *
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		prev = current->prev;

		while (prev && temp->n < prev->n)
		{
			if (temp->next)
				temp->next->prev = prev;

			prev->next = temp->next;
			temp->prev = prev->prev;
			temp->next = prev;
			prev->prev = temp;

			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;

			print_list(*list);
			prev = temp->prev;
		}
		current = current->next;
	}
}
