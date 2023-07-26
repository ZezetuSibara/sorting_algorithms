#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - A doubly linked list node
 * @n: An actual integer stored in the node
 * @prev: Points to the previous element of the list
 * @next: Points to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/** The important prototypes used for Sort Algorithms */
void swap(int *x, int *y);
void sift_down(int *array, size_t max_idx, size_t c_idx, size_t size);
void heap_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void quick_sort_hoare(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);

#endif

