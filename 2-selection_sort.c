#include "sort.h"

void selection_sort(listint_t **list);
/**
 * selection_sort - Function that sorts a doubly linked list of integers
 * in ascending order using Selection Sort.
 *
 * @list: Pointer to a pointer to the head of the list.
 */
void selection_sort(listint_t **list)
{
	listint_t *current, *min;

	if (list == NULL || *list == NULL)
		return;

	current = *list;

	while (current->next != NULL)
	{
		min = current;
		listint_t *inner_current = current->next;

		while (inner_current != NULL)
		{
			if (inner_current->n < min->n)
				min = inner_current;

			inner_current = inner_current->next;
		}

		if (min != current)
		{
			listint_t *temp = current;
			listint_t *prev = current->prev;

			if (prev != NULL)
				prev->next = min;
			else
				*list = min;

			min->prev = prev;
			current->prev = min;
			current->next = min->next;

			if (min->next != NULL)
				min->next->prev = current;

			min->next = temp;
			current = min;
		}
		else
		{
			current = current->next;
		}

		print_list(*list);
	}
}
