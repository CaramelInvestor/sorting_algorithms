#include "sort.h"

/**
 * selection_sort - Function that sorts an array of integers
 * in ascending order using Selection Sort.
 *
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int *temp_array = malloc(sizeof(int) * size);

	if (array == NULL || size < 2)
		return;

	if (temp_array == NULL)
		return;

		
	for (i = 0; i < size; i++)
	{
		temp_array[i] = array[i];
	}

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (temp_array[j] < temp_array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			int temp = temp_array[i];
			temp_array[i] = temp_array[min_idx];
			temp_array[min_idx] = temp;
		}
	}

	for (i = 0; i < size; i++)
	{
		array[i] = temp_array[i];
	}

	free(temp_array);
}

