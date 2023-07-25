#include "sort.h"
#include <stdlib.h>

/**
 * arr_zero_init - start the array by 0
 * @array: the array to start from
 * @size: the actual array size
 */
void arr_zero_init(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * get_max - maximum value in the array is attained
 * @array: the max value  comes from this array
 * @size: the actual array size
 * Return: the maximum array value
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];	/* first index to begin from */

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	return (max);
}

/**
 * sort_counter - used to arrange an array for LSD
 * @array: original array
 * @size: the actual array size
 * @place: where the LSD (least significant digit) is placed
 */
void sort_counter(int *array, size_t size, int place)
{
	int k, *position, *sumPosition, *sorted;
	size_t i, j;

	position = malloc(sizeof(int) * 10);
	if (!position)
		return;
	arr_zero_init(position, 10);

	for (i = 0; i < size; i++)
		position[(array[i] / place) % 10] += 1;    /* the LSD place */

	sumPosition = malloc(sizeof(int) * 10);
	if (!sumPosition)
		return;
	arr_zero_init(sumPosition, 10);
	sumPosition[0] = position[0];   /* first index  made equal */

	for (j = 1; j < 10; j++)
		sumPosition[j] = position[j] + sumPosition[j - 1];

	free(position);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	arr_zero_init(sorted, size);

	for (k = size - 1; k >= 0; k--)  /* sort the array */
	{
		sumPosition[(array[k] / place) % 10] -= 1;
		sorted[sumPosition[(array[k] / place) % 10]] = array[k];
	}
	free(sumPosition);

	for (i = 0; i < size; i++)  /*the array is improved */
		array[i] = sorted[i];
	free(sorted);
}

/**
 * radix_sort -executes the the LSD (least significant Digit)
 * @array: the sorted array
 * @size: the actual array size
 */
void radix_sort(int *array, size_t size)
{
	int max, position = 1;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	while ((max / position) > 0)
	{
		sort_counter(array, size, position);
		print_array(array, size);
		position *= 10;
	}
}
