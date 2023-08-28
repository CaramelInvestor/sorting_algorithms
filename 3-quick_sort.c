#include "sort.h"

/**
 * hoare_partition - Function that partitions an array
 * using Hoare partition scheme.
 * @array: The array to be partitioned.
 * @low: The lower index of the partition.
 * @high: The higher index of the partition.
 * @size: Size of the array.
 *
 * Return: The index where the pivot ends up.
 */
size_t hoare_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot, temp;
	ssize_t i, j;

	pivot = array[low];
	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * quicksort_recursive - Recursively sorts an array using Quick Sort.
 * @array: The array to be sorted.
 * @low: The lower index of the partition.
 * @high: The higher index of the partition.
 * @size: Size of the array.
 */
void quicksort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);

		quicksort_recursive(array, low, pivot, size);
		quicksort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
