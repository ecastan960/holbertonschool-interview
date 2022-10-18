#include "search_algos.h"

/**
 * advanced_binary - function
 *
 * @array: array
 * @size: size
 * @value: value
 *
 * Return: index
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i = 0, half = 0, index = 0;
	int tmp;

	if (!array)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i == size - 1)
			printf("\n");
		else
			printf(", ");
	}

	half = (size - 1) / 2;
	if (array[half] == value)
	{
		if (size == 1 || array[half - 1] < value)
			return (half);
	}
	else if (size == 1)
	{
		return (-1);
	}
	if (array[half] < value)
	{
		index += half + 1, array += half + 1;
		if (size % 2 != 0)
			half--;
	}
	half++;
	tmp = advanced_binary(array, half, value);
	if (tmp != -1)
		return (tmp + index);
	return (-1);
}
