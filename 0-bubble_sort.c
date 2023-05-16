#include "sort.h"

/**
 * bubble_sort - bubble sort the given list
 * @array: array to be sorted
 * @size: number of elements in the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;

	i = 0;
	while (i < (size - 1))
	{
		j = 0;
		while (j < (size - i - 1))
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
			j = j + 1;
		}
		i = i + 1;
	}
}
