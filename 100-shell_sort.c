#include "sort.h"

/**
 * find_pow - will be used to find power of a  particular number
 * @x: the actual number
 * @y: the actual power value
 * * Return: the power of x will be returned
 */
int find_pow(int x, size_t y)
{
	if (y == 0)
		return (1);

	return (x * find_pow(x, y - 1));
}

/**
 * seq_generator - will be used to generate a sequence
 * @size: the actual sequence size
 * Return: points to the sequence address
 */
int *seq_generator(size_t size)
{
	size_t n = 0;
	int i = 0, nth_term, *sequence;

	sequence = malloc(sizeof(int) * size);
	if (sequence == NULL)
		return (NULL);

	nth_term = 0;
	while (n < size)
	{
		nth_term = nth_term + find_pow(3, n);
		sequence[i] = nth_term;
		n++;
		i++;
	}
	return (sequence);
}

/**
 * reverse_seq - the reverse sequence to be used
 * @sequence: points to the sequesnce address
 * @size: the actual sequence size
 * Return: a reversed sequence
 */
int *reverse_seq(int *sequence, size_t size)
{
	int *rev_seq;
	size_t i = 0, seq_index;

	rev_seq = malloc(sizeof(int) * size);
	if (rev_seq == NULL)
		return (NULL);

	seq_index = size - 1;
	while (i < size)
	{
		rev_seq[i] = sequence[seq_index];
		i++;
		seq_index--;
	}
	return (rev_seq);
}

/**
 * shell_sort - the Shell sort algorithm will be used to sort
 * @array: the array to sort
 * @size: the actual array size
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int j, flag = 0;
	int temp, *sequence, *rev_seq, hold;
	size_t i, seq_index = 0;

	sequence = seq_generator(size);
	if (sequence == NULL)
		return;

	rev_seq = reverse_seq(sequence, size);
	if (rev_seq == NULL)
		return;

	while (seq_index < size)
	{
		for (i = rev_seq[seq_index]; i < size; i++)
		{
			temp = array[i];
			hold = rev_seq[seq_index];
			for (j = i; j >= hold && array[j - hold] > temp; j -= hold)
			{
				array[j] = array[j - rev_seq[seq_index]];
			}
			array[j] = temp;
			flag = 1;
		}
		if (flag)
			print_array(array, size);
		seq_index++;
	}
	free(sequence);
	free(rev_seq);
}
