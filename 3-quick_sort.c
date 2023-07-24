#include "sort.h"

/**
 * swap_pos - the value positions are changed in array
 * @array: the actual array to change
 * @first: the first index
 * @second: the second index
 */
void swap_pos(int **array, size_t first, size_t second)
{
	int holder;

	holder = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = holder;
}

/**
 * partition - splits the array will be split  into two parts
 * @array: the actual array to sort
 * @lower: the lower boundary
 * @upper: the upper boundary
 * @size: the actual array size
 * Return: the sorted pivot index
 */
size_t partition(int **array, size_t lower, size_t upper, size_t size)
{
	size_t before, after, pivot;

	pivot = upper;
	before = lower;

	for (after = before; after < upper; after++)
	{
		/* is array lesser than pivot */
		if ((*array)[after] <= (*array)[pivot])
		{
			if (before != after)
			{
				swap_pos(array, before, after);
				print_array(*array, size);
			}
			before += 1;
		}
	}

	/* pivot changed to initial position */
	if (before != after)
	{
		swap_pos(array, before, after);
		print_array(*array, size);
	}
	return (before);
}
/**
 * sorter - the array sorts to recur
 * @array: the actual array to sort
 * @lb: the lower bound
 * @ub: the upper bound
 * @size: the actual array size
 */
void sorter(int **array, size_t lb, size_t ub, size_t size)
{
	size_t sorted_index;

	/* breakpoint to repeat */
	if (lb < ub && *array)
	{
		sorted_index = partition(array, lb, ub, size);

		/* repetitiive sort */
		if (sorted_index - lb > 1)	/* more than one element to be shown */
			sorter(array, lb, sorted_index - 1, size);    /* lower boundary sorted */

		if (ub - sorted_index > 1)
			sorter(array, sorted_index + 1, ub, size);    /* upper boundary sorted */
	}
}

/**
 * quick_sort - applies the quick sort algorithm is used
 * @array: the actual array to sort
 * @size: actual array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	/* create the sorter function for the array */
	sorter(&array, 0, size - 1, size);
}
