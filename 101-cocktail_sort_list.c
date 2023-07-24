#include "sort.h"

/**
 * nodes_swap - the nodes in a list are interchanged
 * @list: the first node
 * @first: the first node address
 * @second: the second node address
 */
void nodes_swap(listint_t **list, listint_t *first, listint_t *second)
{
	if (!first->prev)	/* the first node */
		*list = second;
	else
		first->prev->next = second;

	second->prev = first->prev;

	if (second->next)	/* the last node */
		second->next->prev = first;


	first->prev = second;
	first->next = second->next;
	second->next = first;
}

/**
 * cocktail_sort_list - a tool used to sort numbers
 * @list: the first node
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *future;
	int swapped = 1;

	if (!list || !(*list) || !(*list)->next)  /* one node */
		return;

	future = *list;
	while (swapped)
	{
		swapped = 0;
		while (future->next)    /* do forward cut across */
		{
			if (future->n > future->next->n)
			{
				nodes_swap(list, future, future->next);
				print_list(*list);
				swapped = 1;
				continue;
			}
			future = future->next;
		}

		if (!swapped)   /* a sorted list*/
			break;

		swapped = 0;
		while (future->prev)    /* do backward cut across */
		{
			if (future->n < future->prev->n)
			{
				nodes_swap(list, future->prev, future);
				print_list(*list);
				swapped = 1;
				continue;
			}
			future = future->prev;
		}
	}
}
