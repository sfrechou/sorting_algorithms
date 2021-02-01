#include "sort.h"

/**
 * insertion_sort_list - Implements insertion sort algorithm
 *
 * @list: The doubly linked list to be sorted
*/

void cocktail_sort_list(listint_t **list)
{
    listint_t *p_max = *list, *recorro;
    int i = 0, len = 0;

    while (p_max->next != NULL)
    {
        p_max = p_max->next;
        len++;
    }

    len += 1;

	if (len < 2)
		return;
    while (i < len / 2)
    {
        recorro = *list;
        while (recorro->next != NULL)
        {
            if (recorro->n > recorro->next->n)
            {
                swap(recorro->next, recorro, list);
                print_list(*list);
            }
            else
                recorro = recorro->next;
        }
        while (recorro->prev != NULL)
        {
            if (recorro->n < recorro->prev->n)
            {
                swap(recorro, recorro->prev, list);
                print_list(*list);
            }
            else
                recorro = recorro->prev;
        }
        i++;
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
	listint_t *aux_prev, *aux_next = temp_sort->next;

	swapper = temp_sort->prev;
    if (swapper->prev == NULL)
	{
		temp_sort->prev = NULL;
		temp_sort->next = swapper;
		swapper->prev = temp_sort;
		swapper->next = aux_next;
		aux_next->prev = swapper;
		*list = temp_sort;
	}
	else if (temp_sort->next == NULL)
	{
		aux_prev = swapper->prev;
		aux_prev->next = temp_sort;
		temp_sort->prev = aux_prev;
		temp_sort->next = swapper;
		swapper->prev = temp_sort;
		swapper->next = NULL;
	}
	else
	{
		aux_prev = swapper->prev;
		aux_prev->next = temp_sort;
		temp_sort->prev = aux_prev;
		temp_sort->next = swapper;
		swapper->next = aux_next;
		swapper->prev = temp_sort;
		aux_next->prev = swapper;
	}
	return (list);
}
