#include "sort.h"

/**
 * insertion_sort_list - function to sort
 *@list: value
 * print_list - function to be printed
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cop_list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	cop_list = (*list)->next;

	while (cop_list)
	{
		while (cop_list->prev != NULL && cop_list->n < cop_list->prev->n)
		{
			cop_list->prev->next = cop_list->next;
			if (cop_list->next != NULL)
				cop_list->next->prev = cop_list->prev;
			cop_list->next = cop_list->prev;
			cop_list->prev = cop_list->prev->prev;
			cop_list->next->prev = cop_list;
			if (cop_list->prev == NULL)
				(*list) = cop_list;
			else
			{
				cop_list->prev->next = cop_list;
			}
			print_list(*list);
		}
		cop_list = cop_list->next;
	}
}
