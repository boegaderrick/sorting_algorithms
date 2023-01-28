#include "sort.h"

/**
 * malloc_2d_int - allocates memory for a 2d array
 * @array: pointer to set to the allocated memory
 * @row: number of rows in the 2d array
 * @col: number of columns in the 2d array
 */

void malloc_2d_int(int ***array, int row, int col)
{
	int i;

	*array = malloc(sizeof(int *) * row);
	if (!*array)
		return;

	for (i = 0; i < row; i++)
	{
		(*array)[i] = malloc(sizeof(int) * col);
		if (!(*array)[i])
		{
			free(*array);
			return;
		}
	}
}

/**
 * free_2d_int - frees memory allocated to 2d array
 * @array: address of 2d array
 * @row: number of rows in array
 */
void free_2d_int(int ***array, int row)
{
	int i;

	for (i = 0; i < row; i++)
		free((*array)[i]);
	free(*array);
	*array = NULL;
}

/**
 * radix_sort - implementation of the radix sort algorithm
 * @array: array to be sorted
 * @size: number of elements in array to be sorted
 */
void radix_sort(int *array, size_t size)
{
	size_t i, j, k = 0, l, passes, row, col, next_col[10] = {0};
	int width, largest = 0, **bucket = NULL;
	char *str = NULL, *dup = NULL;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > largest)
			largest = array[i];
	}
	asprintf(&str, "%d", largest);
	passes = strlen(str);
	width = passes;
	free(str);
	malloc_2d_int(&bucket, 10, size);
	if (!bucket)
		return;
	for (i = 0; i < passes; i++)
	{
		for (j = 0; j < size; j++)
		{
			asprintf(&dup, "%0*d", width, array[j]);
			row = dup[passes - i - 1] - '0';
			col = next_col[row];
			bucket[row][col] = array[j];
			next_col[row]++;
			free(dup);
			dup = NULL;
		}
		k = 0;
		for (l = 0; l < 10; l++)
		{
			for (j = 0; j < next_col[l]; j++)
				array[k++] = bucket[l][j];
			next_col[l] = 0;
		}
		print_array(array, size);
	}
	free_2d_int(&bucket, 10);
}
