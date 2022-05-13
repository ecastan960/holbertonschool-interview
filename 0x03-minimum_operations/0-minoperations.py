#!/usr/bin/python3
"""Method File minOperations"""
import math


def minOperations(n):
    """Method that calculates the fewest number of
    operation needed to result in exactly n H characters
    in the file

    Args:
        n (number): input number
    """
    ans = 0
    if n > 1:
        for i in range(2, int(math.sqrt(n) + 1)):
            while n % i == 0:
                ans = ans + i
                n = n // i
    if n > 1:
        return ans + n
    else:
        return ans
