#include <stddef.h>
#include <stdlib.h>
#include <stdlib.h>
#include "sort.h"
/**
 * aux - Auxiliary function
 *
 * @array: array
 * @buffer: buffer
 * @size: size
 * @lsd: lsd
 *
 * Return: void
 */
void aux(int *array, int **buffer, int size, int lsd)
{
	int i;
	int j;
	int num;
	int asize = 10;
	int arr1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		buffer[num][arr1[num]] = array[i];
		arr1[num] += 1;
	}

	for (i = 0, j = 0; i < asize; i++)
	{
		while (arr1[i] > 0)
		{
			array[j] = buffer[i][arr2[i]];
			arr2[i] += 1, arr1[i] -= 1;
			j++;
		}
	}

	print_array(array, size);
}
/**
 * sort - Sort function
 *
 * @array: array
 * @size: size
 * @lsd: lsd
 *
 * Return: void
 */
void sort(int *array, int size, int lsd)
{
	int i;
	int j;
	int num;
	int asize = 10;
	int **buffer;
	int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		arr[num] += 1;
	}

	if (arr[0] == size)
		return;

	buffer = malloc(sizeof(int *) * 10);
	if (!buffer)
		return;

	for (i = 0; i < asize; i++)
		if (arr[i] != 0)
			buffer[i] = malloc(sizeof(int) * arr[i]);

	aux(array, buffer, size, lsd);

	sort(array, size, lsd + 1);

	for (i = 0; i < asize; i++)
		if (arr[i] > 0)
			free(buffer[i]);
	free(buffer);
}
/**
 * radix_sort - Radix sort algorithm function
 *
 * @array: array
 * @size: size
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	sort(array, size, 1);
}
