#include "sort.h"

/**
 * quick_sort - Sorts an array using the Quick Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}

/**
 * recursive_quick_sort - Recursively sorts the partitioned array.
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 */
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		recursive_quick_sort(array, low, pivot - 1, size);
		recursive_quick_sort(array, pivot + 1, high, size);
	}
}

/**
 * partition - Partitions the array and returns the pivot index.
 * @array: The array to be partitioned.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 * Return: The pivot index.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_sort(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_sort(array, size);
	}

	return i + 1;
}

/**
 * swap - Swaps two integer values.
 * @a: The first value.
 * @b: The second value.
 */
void swap(int *a, int *b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

/**
 * print_sort - Prints the array for visualization.
 * @array: The array to be printed.
 * @size: The size of the array.
 */
void print_sort(int *array, size_t size)
{
	print_array(array, size);
}
