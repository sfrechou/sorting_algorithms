#include <stdio.h>
#include "sort.h"
/**
*
*
*/
void merge_sort(int *array, size_t size)
{
    int n = (int)size;
    int *brray;
    brray = malloc(sizeof(int) * size);
    copy_array(array, 0, n, brray);
    topDown_split_merge(brray, 0, n, array);
    free(brray);
}
void topDown_split_merge(int barray[], int start, int end, int array[])
{
    int middle, index;
    if (end - start <= 1)
        return;                                 
    middle = (end + start) / 2;
    topDown_split_merge(array, start, middle, barray);
    topDown_split_merge(array, middle, end, barray);
    printf("Merging...\n");
    topDown_merge(barray, start, middle, end, array);
    printf("[Done]: ");
    for (index = start; index < end; index++)
    {
        printf("%d", array[index]);
        if (index != end - 1)
            printf(", ");
    }
    printf("\n");
}
void topDown_merge(int array[], int start, int  middle, int end, int barray[])
{
    int i = start, j = middle, k, index;

    for (k = start; k < end; k++)
    {
        if (i < middle && (j >= end || array[i] <= barray[j])) 
        {
            barray[k] = array[i];
            i = i + 1;
        }
        else
        {
            barray[k] = array[j];
            j = j + 1;
        }
    }
    printf("[left]: ");
    for (index = start; index < middle; index++)
    {
        printf("%d", array[index]);
        if (index != middle - 1)
            printf(", ");
    }
    printf("\n");
    printf("[right]: ");
    for (index = middle; index < end; index++)
    {
        printf("%d", array[index]);
        if (index != end - 1)
            printf(", ");
    }
    printf("\n");
}
void copy_array(int array[], int start, int end, int barray[])
{
    int k;
    for(k = start; k < end; k++)
        barray[k] = array[k];
}