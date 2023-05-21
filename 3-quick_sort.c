#include "sort.h"

/**
 * swap - swaps position of 2 integers in an array
 * @array: array
 * @a: first integer to be swapped
 * @b: second integer to be swapped
 * @size: size of array
 */
void swap(int *array, int *a, int *b, size_t size)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, size);
}

/**
 * partition - identify the pivot and put it into position
 * @array: name of array
 * @low: index position of lowest number on list
 * @high: index position of highest number on list
 * @size: size of array
 * Return: pivot (int)
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = low;

	while (j < high)
	{
		if (array[j] < pivot)
		{
			i = i + 1;
			if (i != j)
			{
				swap(array, &array[i], &array[j], size);
			}
		}
		j = j + 1;
	}
	if (array[i + 1] != pivot)
	{
		swap(array, &array[i + 1], &array[high], size);
	}
	return (i + 1);
}

/**
 * sort_recursive - sort an array of integers using recursion
 * @array: name of array
 * @low: index position of lowest number on list
 * @high: index position of highest number on list
 * @size: size of array
 */
void sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		sort_recursive(array, low, pivot - 1, size);
		sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	sort_recursive(array, 0, size - 1, size);
}
