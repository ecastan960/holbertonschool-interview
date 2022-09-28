#!/usr/bin/python3
"""_summary_
"""


def rotate_2d_matrix(matrix):
    """_summary_

    Args:
        matrix (_type_): _description_
    """
    matrix.reverse()
    temp_matrix = matrix.copy()

    for i in range(len(matrix)):
        matrix[i] = [row[i] for row in temp_matrix]
