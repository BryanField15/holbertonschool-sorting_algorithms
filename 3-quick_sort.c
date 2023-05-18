#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	size_t pivot;
	size_t j;
	size_t z;
	size_t temp;
	
	j = 0;
	z = size - 1;
	pivot = size/2;
	while (j < z)
	{
		if (array[z] < array[pivot])
		{
			temp = array[z];
			array[z] = array[j];
			array[j] = temp;
			j = j + 1;
			print_array(array, size);
		}
		z = z - 1;
	}
}
