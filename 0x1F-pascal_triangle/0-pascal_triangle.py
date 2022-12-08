#!/usr/bin/python3
"""_summary_
"""


def pascal_triangle(n):
    """_summary_

    Args:
    n (_type_): _description_

    Returns:
    _type_: _description_
    """
    triangle = []
    if (n <= 0):
        return triangle
    for i in range(0, n):
        row = []
        for j in range(0, i + 1):
            if (j == 0) or (j == i):
                row.append(1)
            elif (j >= 1) and (j != i):
                row.append(triangle[i - 1][j - 1] + triangle[i - 1][j])
        triangle.append(row)
    return triangle
