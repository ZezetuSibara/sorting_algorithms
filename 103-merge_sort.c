#include "sort.h"

/**
 * print_parse - the value in array is printed
 * @array: prints the actual array
 * @text: the text to be printed
 * @low: the lower bound
 * @high: the upper bound
 */
void print_parse(int *array, const char *text, size_t low, size_t high)
{
	size_t i;
	char *separator = "";

	printf("[%s]: ", text);
	for (i = low; i <= high; i++)
	{
		printf("%s%d", separator, array[i]);
		separator = ", ";
	}
	printf("\n");
}
/**
 * join_parse - the values are joined and sorted in the array
 * @arr: the sorted array
 * @low: the starting array index
 * @high: the ending array index
 * @mid: the split array midpoint
 * @copy: where sorted values will be stored
 */
void join_parse(int *arr, size_t low, size_t high, size_t mid, int *copy)
{
	size_t hStart = mid + 1, newIndex, lStart = low, i;

	printf("Merging...\n");
	print_parse(arr, "left", low, mid);
	print_parse(arr, "right", mid + 1, high);

	for (newIndex = low; newIndex <= high; newIndex++)  /* fill the sorted values */
	{
		if ((lStart <= mid && arr[lStart] <= arr[hStart]) || hStart > high)
			copy[newIndex] = arr[lStart++];
		else
			copy[newIndex] = arr[hStart++];
	}

	for (i = low; i <= high; i++)   /* change the initial array */
		arr[i] = copy[i];

	print_parse(arr, "Done", low, high);
}

/**
 * parser - do  merge sort and sort the given array repeatedly.
 * @array: an actual array to sort
 * @lb: the lower bound
 * @ub: the upper bound
 * @copy: where sorted values will be stored
 */
void parser(int *array, size_t lb, size_t ub, int *copy)
{
	size_t mid;

	if (lb < ub)
	{
		mid = (ub + lb - 1) / 2;

		parser(array, lb, mid, copy);
		parser(array, mid + 1, ub, copy);

		join_parse(array, lb, ub, mid, copy);
	}
}

/**
 * merge_sort - a tool used to sort an array of integers
 * @array: the actual array to sort
 * @size: the actual array size
 */
void merge_sort(int *array, size_t size)
{
	int *clone;

	if (!array || size < 2)   /* one  array value or less */
		return;

	clone = malloc(sizeof(int) * size);
	if (!clone)
		return;

	parser(array, 0, size - 1, clone);
	free(clone);
}
