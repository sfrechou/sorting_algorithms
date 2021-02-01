#include "sort.h"

/**
 * insertion_sort_list - Implements insertion sort algorithm
 *
 * @list: The doubly linked list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp_n, *temp_sort, *swapper;
	int len = dlistint_len(*list);

	if (!list || *list == NULL)
		return;

	if (len < 2)
		return;

	temp_n = *list;
	if (len == 2)
	{
		temp_n = temp_n->next;
		if (temp_n->n < (temp_n->prev)->n)
		{
			swap(temp_n->prev, temp_n, list);
			print_list(*list);
		}
		return;
	}
	while (temp_n != NULL)
	{
		temp_sort = temp_n;
		if (temp_sort->prev != NULL)
		{
			while (temp_sort->n < (temp_sort->prev)->n && temp_sort->prev != NULL)
			{
				swapper = temp_sort->prev;
				if (swapper->prev == NULL)
				{
					swap(swapper, temp_sort, list);
					print_list(*list);
					break;
				}
				swap(swapper, temp_sort, list);
				print_list(*list);
			}
		}
		temp_n = temp_n->next;
	}
}

/**
 * swap - Swaps two nodes in a doubly linked list
 *
 * @temp_sort: Auxiliary node
 * @swapper: Auxiliary node
 * @list: The doubly linked list to be sorted
 *
 *Return: Returns a list
*/
listint_t **swap(listint_t *temp_sort, listint_t *swapper, listint_t **list)
{
	listint_t *aux_prev = temp_sort->prev, *aux_next = swapper->next;

	if (dlistint_len(*list) == 2)
	{
		temp_sort->next = NULL;
		swapper->prev = NULL;
		temp_sort->prev = swapper;
		swapper->next = temp_sort;
		*list = swapper;
	}
	else if (temp_sort->prev == NULL)
	{
		temp_sort->next = aux_next;
		swapper->prev = NULL;
		temp_sort->prev = swapper;
		swapper->next = temp_sort;
		aux_next->prev = temp_sort;
		*list = swapper;
	}
	else if (swapper->next == NULL)
	{
		temp_sort->prev = swapper;
		swapper->next = temp_sort;
		swapper->prev = aux_prev;
		aux_prev->next = swapper;
		temp_sort->next = NULL;
	}
	else
	{
		temp_sort->prev = swapper;
		swapper->next = temp_sort;
		temp_sort->next = aux_next;
		swapper->prev = aux_prev;
		aux_prev->next = swapper;
		aux_next->prev = temp_sort;
	}
	return (list);
}

int dlistint_len(const listint_t *list)
{
	int n = 0;

	if (list == NULL)
		return (0);
	while (list != NULL)
	{
		n++;
		list = list->next;
	}
	return (n);
}
