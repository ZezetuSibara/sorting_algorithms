#include "sort.h"

/**
 * shell_sort - used to sort the array
 * @array: an array of data that is not sorted
 * @size: the actual array size
 * Return: Void
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t j, gap, n;

	gap = 1;
	if (!array || size < 2)
		return;
	/* the Knuth sequence is created */
	while (gap < size / 3)
		gap = gap * 3 + 1;
	/* Do the largest gap first */
	while (gap > 0)
	{
		/* The first gap elements array */
		/* one more element to be added until array gap sorted */
		for (j = gap; j < size; j += 1)
		{
			/* add array[j] to the elements */
			tmp = array[j];
			/* shift earlier gap-sorted elements */
			for (n = j; n >= gap && tmp < array[n - gap]; n -= gap)
				array[n] = array[n - gap];
			/* put the original array in correct location */
			array[n] = tmp;
		}
		/* the interval is decreased */
		gap /= 3;
		/*  print array each time  the interval is decreased */
		print_array(array, size);
	}
}
