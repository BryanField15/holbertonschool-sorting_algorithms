#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t position;
	int swap;

	i = 0;
	while (i < (size - 1))
	{
		position = i;
		j = i + 1;
		while (j < size)
		{
			if (array[position] > array[j])
			{
				position = j;
			}
			j = j + 1;
		}

		if (position != i)
		{
			swap = array[i];
			array[i] = array[position];
			array[position] = swap;
			print_array(array, size);
		}
		i = i + 1;
	}
}
