#include "sort.h"

/**
 * arr_zero_init - use 0 to initialize the array
 * @array: the innitialized array
 * @size: the actual array size
 */
void arr_zero_init(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * get_max - the maximum value in the array is attanied
 * @array: the array to attain the value from
 * @size: the actual array size
 * Return: the array maximum value
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	if (size < 2)
		return (0);

	max = array[0];	/* first index */

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - will be used to sort an array
 * @array: the actual array
 * @size: the array size
 */
void counting_sort(int *array, size_t size)
{
	int k = get_max(array, size), j, *position, *sumPosition, *sorted;
	size_t i;

	if (k == 0)
		return;

	position = malloc(sizeof(int) * (k + 1));
	if (!position)
		return;
	arr_zero_init(position, k + 1);

	for (i = 0; i < size; i++)
		position[array[i]] += 1;    /* one is set to the positions */

	sumPosition = malloc(sizeof(int) * (k + 1));
	if (!sumPosition)
		return;
	arr_zero_init(sumPosition, k + 1);
	sumPosition[0] = position[0];   /* first index equal */

	for (j = 1; j < (k + 1); j++)
		sumPosition[j] = position[j] + sumPosition[j - 1];

	free(position), print_array(sumPosition, k + 1);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	arr_zero_init(sorted, size);

	for (i = 0; i < size; i++)  /* the array gets sorted */
	{
		sumPosition[array[i]] -= 1;
		sorted[sumPosition[array[i]]] = array[i];
	}
	free(sumPosition);

	for (i = 0; i < size; i++)  /* the array gets updated */
		array[i] = sorted[i];
	free(sorted);
}
