#!/usr/bin/python3
"""_summary_
"""


def island_perimeter(grid):
    """_summary_

    Args:
        grid (_type_): _description_
    """
    if not grid:
        return 0
    perimeter = 0
    r = len(grid)
    for i in range(r):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                if i == r - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
                if j == len(grid[i]) - 1 or grid[i][j + 1] == 0:
                    perimeter += 1
    return perimeter
