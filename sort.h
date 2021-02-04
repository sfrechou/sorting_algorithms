#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t **swap(listint_t *temp_sort, listint_t *swapper, listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void r_quick_sort(int *array, int lo, int hi, size_t size);
int partition(int *array, int lo, int hi, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[]);
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[]);
void CopyArray(int A[], int iBegin, int iEnd, int B[]);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size);
void siftDown(int *array, int start, int end, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void merge_up(int *array, size_t size);
void merge_down(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int h_partition(int *array, int start, int end, size_t size);
void h_quick_sort(int *array, int start, int end, size_t size);

#endif
