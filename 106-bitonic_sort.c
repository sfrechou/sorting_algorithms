#include "sort.h"

/**
 * radix_sort - Implements radix sort algorithm - LSD
 *
 * @array: The array to be sorted
 * @size: Size of the array
*/
void bitonic_sort(int *array, size_t size)
{
    int s, i;

	for (s = 2; s <= (int)size; s *= 2)
	{
		for (i = 0; i < (int)size;)
		{
			merge_up((array + i), s);
			merge_down((array + i + s), s);
			i += s * 2;
		}
	}
	print_array(array, size);
	printf("Hi\n");
}

void merge_up(int *array, size_t size)
{
    int step = (int)size / 2, i, j, k, temp;
    while (step > 0)
	{
        for (i = 0; i < (int)size; i += step * 2)
		{
            for (j = i, k = 0; k < step; j++, k++)
			{
				if (array[j] > array[j+step])
				{
					temp = array[j];
					array[j] = array[j + step];
					array[j + step] = temp;
				}
            }
        }
        step /= 2;
    }
}

void merge_down(int *array, size_t size)
{
	int step = (int)size / 2, i, j, k, temp;
	while (step > 0)
	{
		for (i = 0; i < (int)size; i += step * 2)
		{
			for (j = i, k = 0; k < step; j++, k++)
			{
				if (array[j] < array[j + step])
				{
					temp = array[j];
					array[j]=array[j + step];
					array[j + step] = temp;
				}
			}
		}
		step /= 2;
	}
}



/*	int k, j, i, l, temp;

	for (k = 2; k <= (int)size; k *= 2)
	{
		for (j = k / 2; j > 0; j /= 2)
		{
			for (i = 0; i < (int)size; i++)
			{
				l = i ^ j;
				if (l > i)
					if (((i & k) == 0 && array[i] > array[l]) || ((i & k) != 0 && array[i] < array[j]))
					{
						temp = array[i];
						array[i] = array[l];
						array[l] = temp;
					}
			}
		}
	}
	*/
