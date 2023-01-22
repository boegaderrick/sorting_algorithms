#include "sort.h"

/**
 * selection_sort - implements the selection sort algorithm
 * @array: array of ints to be sorted
 * @size: size of array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, pos;
	int min, temp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				pos = j;
			}
		}
		if (min != array[i])
		{
			temp = array[i];
			array[i] = min;
			array[pos] = temp;
			print_array(array, size);
		}
	}
}
