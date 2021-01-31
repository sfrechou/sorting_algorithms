#include "sort.h"

/**
 * quick_sort - Implements quick sort
 *
 * @array: The array list to be sorted
 * @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	int lo = 0, hi = size - 1;

	r_quick_sort(array, lo, hi, size);
}

/**
 * r_quick_sort - Implements quick sort
 *
 * @array: The array list to be sorted
 * @lo: low index
 * @hi: high index
 * @size: Size of the array
*/
void r_quick_sort(int *array, int lo, int hi, size_t size)
{
	int p = 0;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		r_quick_sort(array, lo, p - 1, size);
		r_quick_sort(array, p + 1, hi, size);
	}
}

/**
 * partition - Divides array in sub arrays
 *
 * @array: The array list to be sorted
 * @lo: low index
 * @hi: high index
 * @size: Size of the array
 * Return: int
*/
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo, j = 0, swapper = 0;

	for (j = lo; j <= hi; j++)
	{
		if (array[j] < pivot)
		{
			swapper = array[j];
			array[j] = array[i];
			array[i] = swapper;
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swapper = array[i];
	array[i] = array[hi];
	array[hi] = swapper;
	if (array[hi] != pivot)
		print_array(array, size);
	return (i);
}
