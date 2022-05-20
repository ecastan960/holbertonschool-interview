#include "sandpiles.h"

/**
 * sum - Sums two grids
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 */
void sum(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}

/**
 * stable - checks if grid is stable
 * @temp: 3x3 grid
 * Return: 1 if stable, 0 otherwise
 *
 */
int stable(int temp[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		if (temp[i][j] > 3)
		{
			return (0);
		}
	}
	return (1);
}

/**
 * print - Print 3x3 grid
 * @temp: 3x3 grid
 *
 */
void print(int temp[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j > 0)
			{
				printf(" ");
			}
			printf("%d", temp[i][j]);
		}
		printf("\n");
	}
}

/**
 * toppling - toppling round
 * @temp: 3x3 grid
 *
 */
void toppling(int temp[3][3])
{
	int k;
	int l;
	int grid[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
	};

	for (k = 0; k < 3; k++)
	{
		for (l = 0; l < 3; l++)
		{
			if (temp[k][l] >= 4)
			{
				grid[k][l] = grid[k][l] - 4;
				if ((k + 1) < 3)
				{
					grid[k + 1][l]++;
				}
				if ((k - 1) >= 0)
				{
					grid[k - 1][l]++;
				}
				if ((l + 1) < 3)
				{
					grid[k][l + 1]++;
				}
				if ((l - 1) >= 0)
				{
					grid[k][l - 1]++;
				}
			}
		}
	}
	sum(temp, grid);
}

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum(grid1, grid2);
	while (stable(grid1) == 0)
	{
		printf("=\n");
		print(grid1);
		toppling(grid1);
	}
}
