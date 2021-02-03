#include <stdio.h>
#include "sort.h"
/**
 * merge_sort - Implements merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
*/
void merge_sort(int *array, size_t size)
{
	int n = (int)size;
	int *brray;

	brray = malloc(sizeof(int) * size);
	CopyArray(array, 0, n, brray);
	TopDownSplitMerge(brray, 0, n, array);
	free(brray);
}

/**
 * TopDownSplitMerge - Splits
 *
 * @B: The array
 * @iBegin: Beginning value
 * @iEnd: End value
 * @A: The other array
*/
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
	int iMiddle, m;

	if (iEnd - iBegin <= 1)
		return;
	iMiddle = (iEnd + iBegin) / 2;
	TopDownSplitMerge(A, iBegin,  iMiddle, B);
	TopDownSplitMerge(A, iMiddle, iEnd, B);
	printf("Merging...\n");
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
	printf("[Done]: ");
	for (m = iBegin; m < iEnd; m++)
	{
		printf("%d", A[m]);
		if (m != iEnd - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * TopDownMerge - Splits
 *
 * @A: The array
 * @iBegin: Beginning value
 * @iMiddle: Middle value
 * @iEnd: End value
 * @B: The other array
*/
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
	int i = iBegin, j = iMiddle, k, m;

	for (k = iBegin; k < iEnd; k++)
	{
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i = i + 1;
		}
		else
		{
			B[k] = A[j];
			j = j + 1;
		}
	}
	printf("[left]: ");
	for (m = iBegin; m < iMiddle; m++)
	{
		printf("%d", A[m]);
		if (m != iMiddle - 1)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (m = iMiddle; m < iEnd; m++)
	{
		printf("%d", A[m]);
		if (m != iEnd - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * CopyArray - Splits
 *
 * @A: The array
 * @iBegin: Beginning value
 * @iEnd: End value
 * @B: The other array
*/
void CopyArray(int A[], int iBegin, int iEnd, int B[])
{
	int k;

	for (k = iBegin; k < iEnd; k++)
		B[k] = A[k];
}
