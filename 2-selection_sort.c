#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in ascending order
 * using the selection sort algorithm.
 * @size: size of the array
 * @array: the array to sort
 * Return: (void)
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			array[i] ^= array[min];
			array[min] ^= array[i];
			array[i] ^= array[min];

			print_array(array, size);
		}
	}
}
