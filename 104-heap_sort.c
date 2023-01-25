#include "sort.h"

void swap(int *array, int largest, int idx)
{
	int temp;
	
	temp = array[idx];
	array[idx] = array[largest];
	array[largest] = temp;
}

void heapify(int *array, int size, int idx)
{
	int largest = idx, l = idx * 2, r = l + 1;

	/*if (l <= size && array[l] > array[r])
		largest = l;
	else if (r <= size)
		largest = r;*/

	if (l <= size && array[l] > array[largest])
		largest = l;
	if (r <= size && array[r] > array[largest])
		largest = r;

	if (largest != idx)
	{
		swap(array, largest, idx);
		heapify(array, size, largest);
	}
}

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (size / 2); i >= 1; i--)
		heapify(array, size - 1, i);

	/*for (i = size - 1; i >= 0; i--)
	{
		swap(array, i
		sort(array, i, 1);*/
}
