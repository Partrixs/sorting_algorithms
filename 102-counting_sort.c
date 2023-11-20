#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maxed, f;

	for (maxed = array[0], f = 1; f < size; f++)
	{
		if (array[f] > maxed)
			maxed = array[f];
	}

	return (maxed);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maxed, f;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maxed = get_max(array, size);
	count = malloc(sizeof(int) * (maxed + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (f = 0; f < (maxed + 1); f++)
		count[f] = 0;
	for (f = 0; f < (int)size; f++)
		count[array[f]] += 1;
	for (f = 0; f < (maxed + 1); f++)
		count[f] += count[f - 1];
	print_array(count, maxed + 1);

	for (f = 0; f < (int)size; f++)
	{
		sorted[count[array[f]] - 1] = array[f];
		count[array[f]] -= 1;
	}

	for (f = 0; f < (int)size; f++)
		array[f] = sorted[f];

	free(sorted);
	free(count);
}
