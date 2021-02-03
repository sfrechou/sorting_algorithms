#include <stdio.h>
#include "sort.h"
/**
 * heap_sort - Implements heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
    int end, temp = 0;

    heapify(array, size);

    end = (int)size - 1;
    while (end > 0)
    {
        temp = array[end];
        array[end] = array[0];
        array[0] = temp;
        end = end - 1;
        print_array(array, size);
        siftDown(array, 0, end, size);
    }
}

void heapify(int *array, size_t size)
{
    int start = ((int)size - 2) / 2;

    while (start >= 0)
    {
        siftDown(array, start, size - 1, size);
        start = start - 1;
    }
}

void siftDown(int *array, int start, int end, size_t size)
{
    int root;
    root = start;

    while (root * 2 + 1 <= end)
    {
        int child, temp = 0;

        child = root * 2 + 1;
        if (child + 1 <= end && array[child] < array[child + 1])
            child += 1;
        if (array[root] < array[child])
        {
            temp = array[root];
            array[root] = array[child];
            array[child] = temp;
            root = child;
            print_array(array, size);
        }
        else
            return;
    }
}
