#include "sort.h"
/**
 * selection_sort -Select sorts an array of integers in ascending order
 * @array: array of integers
 * @size: array size
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx_min;
	int min;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		idx_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				idx_min = j;
			}
		}
		if (min != array[i])
		{
			array[idx_min] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}

