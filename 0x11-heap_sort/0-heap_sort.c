#include "sort.h"

/**
 * maxHeap - makes array into a heap
 * @array: ptr to int array
 * @size: size of array
 * @i: max point
 * @original: original array size
 */
void maxHeap(int *array, int size, int i, int original)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && array[max] < array[left])
	{
		max = left;
	}

	if (right < size && array[max] < array[right])
	{
		max = right;
	}

	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, original);
		maxHeap(array, size, max, original);
	}
}

/**
 * heap_sort - heap sort
 * @array: pointer to array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!size || !array)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		maxHeap(array, size, i, size);
	}
	for (i = size - 1; i > 0; i--)
	{
		if (array[0] >= array[i])
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
		}
		maxHeap(array, i, 0, size);
	}
}

/**
 * swap - swaps elements of arrays
 * @array1: pointer to 1st element
 * @array2: pointer to 2nd element
 */
void swap(int *array1, int *array2)
{
	int temp;

	temp = *array1;
	*array1 = *array2;
	*array2 = temp;
}
