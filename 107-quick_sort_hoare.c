#include "sort.h"

/**
 * quick_sort_hoare - Implements quick sort algorithm - Hoare
 *
 * @array: The array to be sorted
 * @size: Size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
	int lo = 0, hi = (int)size - 1;

	if (size < 2)
		return;

	h_quick_sort(array, lo, hi, size);
}

/**
 * h_quick_sort - Implements quick sort algorithm - Hoare
 *
 * @array: The array to be sorted
 * @start: Start value
 * @end: end value
 * @size: Size of the array
*/
void h_quick_sort(int *array, int start, int end, size_t size)
{
	int i;

	if (end - start < 2)
		return;
	i = h_partition(array, start, end, size);
	h_quick_sort(array, start, i, size);
	h_quick_sort(array, i, end, size);
}

/**
 * h_partition - Implements quick sort algorithm - Hoare
 *
 * @array: The array to be sorted
 * @start: Start value
 * @end: end value
 * @size: Size of the array
 * Return: int
*/
int h_partition(int *array, int start, int end, size_t size)
{
	int x = array[start], i = start - 1, j = end, temp = 0;

	while (1)
	{
		while (array[j] > x)
			j--;
		while (array[i] < x)
			i++;
		if  (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
		else
			return (j + 1);
	}
}
