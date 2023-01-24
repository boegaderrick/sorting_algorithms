#include "sort.h"

/**
 * counting_sort - implementation of the counting sort algorithm
 * @array: pointer to head node of array to be sorted
 * @size: lenght of array to be sorted
 */
void counting_sort(int *array, size_t size)
{
	size_t i = 0;
	int j, *counter, largest = 0, *dup;

	if (size < 2)
		return;

	dup = malloc(sizeof(int) * size);
	while (i < size)
	{
		if (array[i] > largest)
			largest = array[i];
		dup[i] = array[i];
		i++;
	}
	largest += 1;

	counter = (int *)calloc(largest, sizeof(int));

	for (i = 0; i < size; i++)
		counter[array[i]]++;

	for (j = 1; j < largest; j++)
		counter[j] += counter[j - 1];

	print_array(counter, largest);

	for (i = 0; i < size; i++)
	{
		array[counter[dup[i]] - 1] = dup[i];
		counter[dup[i]]--;
	}

	free(counter);
	free(dup);
}
