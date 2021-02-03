#include "sort.h"

/**
 * radix_sort - Implements radix sort algorithm - LSD
 *
 * @array: The array to be sorted
 * @size: Size of the array
*/
void radix_sort(int *array, size_t size)
{
    int max = 0, cont = 1, i, j = 0, base = 0, div = 1, m;
	int *sort, *array2;

	array2 = malloc(sizeof(int) * size);
    for (i = 0; i < (int)size; i++)
    {
        if (array[i] > max)
            max = array[i];
		array2[i] = array[i];
    }
    while (max / 10 > 0)
    {
        cont++;
        max /= 10;
    }

	sort = malloc(sizeof(int) * size);

    while (cont > 0)
    {
		j = 0;
		while (j < (int)size)
		{
			for (base = 0; base < 10; base++)
			{
				for (i = 0; i < (int)size; i++)
				{
					if (array2[i] / div % 10 == base)
					{
						sort[j] = array2[i];
						j++;
					}
				}
			}
		}
		print_array(sort, size);
		for (m = 0; m < (int)size; m++)
		{
			array2[m] = sort[m];
		}
		div *= 10;
		cont -= 1;
    }
	for (i = 0; i < (int)size; i++)
	{
		array[i] = sort[i];
	}
	free(array2);
	free(sort);
}