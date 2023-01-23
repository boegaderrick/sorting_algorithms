#include "sort.h"

/**
 * head_swap - function to swap nodes while traversing the list forwards
 * @list: pointer to head node of list
 * @curr: pointer to node to be swapped
 * @temp: pointer to node to be swapped
 */
void head_swap(listint_t **list, listint_t *curr, listint_t *temp)
{
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
}

/**
 * tail_swap - function to swap nodes while traversing the list backwards
 * @list: pointer to head node of list
 * @tail: pointer to node to be swapped
 * @temp: pointer to node to be swapped
 */
void tail_swap(listint_t **list, listint_t *tail, listint_t *temp)
{
	tail->prev = tail->prev->prev;
	if (tail->prev)
		tail->prev->next = tail;
	temp->next = tail->next;
	if (temp->next)
		temp->next->prev = temp;
	tail->next = temp;
	temp->prev = tail;
	if (!tail->prev)
		*list = tail;
}

/**
 * cocktail_sort_list - linked list implementation of cocktail sort algorithm
 * @list: pointer to head of array to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *tail;
	bool swap = true;

	if (!list || !(*list))
		return;

	while (swap)
	{
		swap = false;
		curr = *list;
		while (curr)
		{
			if (curr->next && curr->n > curr->next->n)
			{
				temp = curr->next;
				head_swap(list, curr, temp);
				print_list(*list);
				swap = true;
				continue;
			}
			if (!curr->next)
				tail = curr;
			curr = curr->next;
		}
		while (tail)
		{
			if (tail->prev && tail->n < tail->prev->n)
			{
				temp = tail->prev;
				tail_swap(list, tail, temp);
				print_list(*list);
				swap = true;
				continue;
			}
			tail = tail->prev;
		}
	}
}
