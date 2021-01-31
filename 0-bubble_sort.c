#include "sort.h"

/**
 * bubble_sort - Implements bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int temp;

	n = size - 1;

	if (size < 2)
		return;

	for (; n > 0; n -= 1)
	{
		for (i = 0; i < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
}
