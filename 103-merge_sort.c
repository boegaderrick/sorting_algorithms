#include "sort.h"

/**
 * output - prints part of an array to stdout
 * @array: pointer to array to be printed
 * @l: lower bound of part to be printed
 * @h: upper bound of part to be printed
 */
void output(int *array, int l, int h)
{
	int i;

	for (i = l; i < h; i++)
	{
		if (i > l)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * merge - merges sorted sub-arrays
 * @array: pointer to array to be sorted
 * @temp: pointer to address to temporarily store sorted elements of array
 * @l: lower bound of left sub-array
 * @mid: middle point dividing left and right sub-arrays
 * @h: upper bound of right sub-array
 */
void merge(int *array, int *temp, int l, int mid, int h)
{
	int i = l, j = mid, k = l;

	printf("Merging...\n[left]: ");
	output(array, l, mid);
	printf("[right]: ");
	output(array, mid, h);

	while (i < mid && j < h)
	{
		if (array[i] < array[j])
			temp[k] = array[i++];
		else
			temp[k] = array[j++];
		k++;
	}
	for (; i < mid; i++)
		temp[k++] = array[i];

	for (; j < h; j++)
		temp[k++] = array[j];

	printf("[done]: ");
	output(temp, l, h);
	for (i = l; i < h; i++)
		array[i] = temp[i];
}

/**
 * sort_r - recursive function that divides array to sub-arrays
 * @array: pointer to array to be sorted
 * @temp: pointer to address to temporarily store sorted elements
 * @l: lower bound of sub-array
 * @h: upper bound of sub-array
 */
void sort_r(int *array, int *temp, int l, int h)
{
	int mid;

	if (h - l > 1)
	{
		mid = l + (h - l) / 2;
		sort_r(array, temp, l, mid);
		sort_r(array, temp, mid, h);
		merge(array, temp, l, mid, h);
	}
}

/**
 * merge_sort - merge sort algorithm wrapper function
 * @array: pointer to array to be sorted
 * @size: length of array
 */
void merge_sort(int *array, size_t size)
{
	int *temp = calloc(size, sizeof(int));

	if (size < 2 || !temp)
		return;

	sort_r(array, temp, 0, size);
	free(temp);
}
