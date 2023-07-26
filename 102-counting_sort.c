#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _bigest -  Populates the largest number
 * @array: The array integer
 * @size: the actual array size
 * Return: The largest number is returned
 */
int _bigest(int *array, size_t size)
{
	size_t i;
	int k = 0;

	for (i = 0; i < size; i++)
	{
		if (k < array[i])
			k = array[i];
	}

	return (k);
}
/**
 * _memset -  An integer array is created
 * @size: the actual array size
 * Return: Returns the array of the integer
 */
int *_memset(int size)
{
	int *ptr = NULL;
	int i;

	ptr = malloc((size) * sizeof(int));

	for (i = 0; i < size; i++)
		ptr[i] = 0;

	return (ptr);
}
/**
 * counting_sort - used to sort the array
 * @array: The array integer
 * @size: the actual array size
 * Return: a list that is sorted
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int k = 0;
	int *ptr = NULL, *sort_ar = NULL;

	if (size < 2)
		return;
	/* the largest number */
	k = _bigest(array, size);
	/* the help array is populated */
	ptr = _memset(k + 1);
	if (!ptr)
		return;
	/* values are set for sorting */
	for (i = 0; i < size; i++)
		for (j = 0; (int)j < k + 1; j++)
			if ((int)j == array[i])
				ptr[j] += 1;
	/* the count in the array is modified */
	for (i = 0; (int)i < k; i++)
		ptr[i + 1] = ptr[i] + ptr[i + 1];
	print_array(ptr, k + 1);
	/* the sort array is created */
	sort_ar = malloc(size * sizeof(int));
	if (!sort_ar)
	{
		free(ptr);
		return;
	}

	for (i = 0; i < size; i++)
	{
		sort_ar[ptr[array[i]] - 1] = array[i];
		ptr[array[i]] -= 1;
	}
	for (j = 0; j < size; j++)
		array[j] = sort_ar[j];

	free(sort_ar);
	free(ptr);
}
