#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	int gap, i;
	if (!array || size < 2)
		return;

	gap = 1;

	while (gap < (int)size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			int temp = array[i];
			int j;

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}

		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
