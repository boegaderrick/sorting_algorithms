#include "sort.h"

/**
 * partition - partition sorts array
 * @array: array to be partitioned/sorted
 * @lb: lower bound of array to be partitioned
 * @ub: upper bound of array to be partitioned
 * @size: size of entire original array
 *
 * Return: middle index of the partitioned array
 */
size_t partition(int *array, size_t lb, size_t ub, size_t size)
{
	size_t piv = ub, i = lb, j = piv, temp;

	while (i < ub)
	{
		if (array[i] > array[piv])
		{
			while (j > i)
			{
				if (array[j] < array[piv])
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
					print_array(array, size);
					break;
				}
				j--;
			}
		}
		i++;
	}
	if (array[j] != array[piv])
	{
		temp = array[j];
		array[j] = array[piv];
		array[piv] = temp;
		print_array(array, size);
	}
	return (j);
}

/**
 * sort - sorts an array using the quick sort algorithm
 * @array: array to be sorted
 * @lb: lower bound of array to be sorted
 * @ub: upper bound of array to be sorted
 * @size: size of entire original array
 */
void sort(int *array, size_t lb, size_t ub, size_t size)
{
	size_t border;

	if (lb < ub)
	{
		border = partition(array, lb, ub, size);
		if (border > 0)
			sort(array, lb, border - 1, size);
		sort(array, border + 1, ub, size);
	}
}

/**
 * quick_sort - wrapper function
 * @array: array to be sorted
 * @size: number of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	sort(array, 0, size - 1, size);
}
