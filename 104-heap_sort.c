#include "sort.h"
/**
 * swap - swapes two integers
 * @x: first argument
 * @y: second argument
 * Return: no return
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
/**
 * sift_down - Heapifies using sift-down algorithm
 * @array: integer array
 * @max_idx: maximum index
 * @p_idx: parent index
 * @size: array size
 * Return: no return
 */
void sift_down(int *array, size_t max_idx, size_t p_idx, size_t size)
{
	size_t c_idx;

	c_idx = p_idx * 2 + 1;
	if (c_idx <= max_idx)
	{
		if (c_idx + 1 <= max_idx)
		{
			if (array[c_idx + 1] > array[c_idx])
				c_idx += 1;
		}
		if (array[c_idx] > array[p_idx])
		{
			swap(&array[c_idx], &array[p_idx]);
			print_array(array, size);
		}
	}
}
/**
 * heap_sort - Heap sorts an array of integers in ascending order
 * @array: array of integers
 * @size: array size
 * Return: no return
 */
void heap_sort(int *array, size_t size)
{
	size_t c_idx, p_idx, j;

	if (size <= 1 || !array)
		return;
	for (j = size - 1; j > 0; j--)
	{
		c_idx = j;
		while (c_idx)
		{
			p_idx = (c_idx - 1) / 2;
			if (array[c_idx] > array[p_idx])
			{
				swap(&array[c_idx], &array[p_idx]);
				print_array(array, size);
				sift_down(array, j, c_idx, size);
			}
			if (c_idx == 1)
			{
				swap(&array[p_idx], &array[j]);
				print_array(array, size);
			}
			c_idx--;
		}
	}
}
