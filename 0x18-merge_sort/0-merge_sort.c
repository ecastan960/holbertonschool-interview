#include "sort.h"

/**
 * merge_sort - sort array
 * @array: Array to merge
 * @size: Length of the array
 */
void merge_sort(int *array, size_t size)
{
	int *a = NULL;

	if (array == NULL || size == 0)
		return;
	a = malloc(size * sizeof(int));
	if (a == NULL)
		return;
}
