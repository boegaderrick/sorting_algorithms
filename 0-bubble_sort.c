#include "sort.h"

/**
 * bubble_sort - implementation of bubble sort sorting algorithm
 * @array: array of ints to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;
	bool swap;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		swap = false;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swap = true;
			}
		}
		if (!swap)
			return;
	}
}
