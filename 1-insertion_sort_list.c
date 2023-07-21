#include "sort.h"
/**
 * insertion_sort_list - insert sorts a doubly linked list in ascending order
 * @list: double linked list listint_t head
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = *list, *temp1, *temp2;
	int k;

	if (!list || !ptr || ptr->next == NULL)
		return;

	ptr = ptr->next;
	while (ptr)
	{
		temp1 = ptr;
		temp2 = ptr->prev;
		k = 0;
		while (temp2)
		{
			if (temp2->n > temp2->next->n)
			{
				k++;
				temp2->next = temp1->next;
				temp1->next = temp2;
				temp1->prev = temp2->prev;
				temp2->prev = temp1;
				if (temp2->next)
					temp2->next->prev = temp2;
				if (temp1->prev)
					temp1->prev->next = temp1;
				else
					*list = temp1;
				temp2 = temp2->prev;
				temp1 = temp1->next;

				if (k == 1)
					ptr = temp1;
				print_list(*list);
			}
			temp1 = temp1->prev;
			temp2 = temp2->prev;
		}
		ptr = ptr->next;
	}
}

