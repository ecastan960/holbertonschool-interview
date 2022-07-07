#include <stdio.h>
#include <stdlib.h>
#include "menger.h"

/**
 * menger - function that draws a Menger
 * @rows: number of rows to draw
 * Return: None.
 */
void menger(int rows)
{
	int i;
	int j;
	int current_row = 0;

	if (rows < 0)
		return;
	current_row = pow(3, rows);
	for (i = 0; i < current_row; i++)
	{
		for (j = 0; j < current_row; j++)
			putchar(draw(i, j));
		putchar('\n');
	}
}
/**
 * draw - draw #
 * @i: rows
 * @j: columns
 * Return: "#" or " "
 */
char draw(int i, int j)
{
	while (i || j)
	{
		if (j % 3 == 1 && i % 3 == 1)
			return (' ');
		i = i / 3;
		j = j / 3;
	}
	return ('#');
}
