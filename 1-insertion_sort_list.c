#include "sort.h"

/**
 * insertion_sort_list - linked list implementation of insertion sort algorithm
 * @list: pointer to head of list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp;
	bool swap = true;

	if (!list || !(*list))
		return;

	while (swap)
	{
		curr = *list;
		while (curr)
		{
			if (curr->next && curr->n > curr->next->n)
			{
				temp = curr->next;
				curr->next = curr->next->next;
				temp->prev = curr->prev;
				if (temp->prev)
					temp->prev->next = temp;
				temp->next = curr;
				curr->prev = temp;
				if (curr->next)
					curr->next->prev = curr;
				if (!temp->prev)
					*list = temp;
				print_list(*list);

				swap = true;
				curr = temp->prev ? temp->prev : temp;
			}
			else
			{
				swap = false;
				curr = curr->next;
			}
		}
	}
}
