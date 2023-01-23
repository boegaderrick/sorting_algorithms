#include "sort.h"

/**
 * shell_sort - shell sort algorithm
 * @array: pointer to array to be sorted
 * @size: lenght of array to be sorted
 */
void shell_sort(int *array, size_t size)
{
	size_t temp, gap = 1 * 3 + 1;
	int i, j, len = size;

	if (size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < len; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (array[j] > array[j + gap])
				{
					temp = array[j + gap];
					array[j + gap] = array[j];
					array[j] = temp;
				}
				else
					break;
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
