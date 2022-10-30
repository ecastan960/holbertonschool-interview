#!/usr/bin/python3
"""_summary_
"""
import math


def makeChange(coins, total):
    """_summary_

    Args:
        coins (_type_): _description_
        total (_type_): _description_
    """
    numberCoins = 0
    remainingTotal = total
    check = 0

    if len(coins) == 0:
        return -1
    for val in coins:
        if (total / val).is_integer():
            check = 0
            break
        check = 1

    if check == 1:
        return -1

    coins.sort(reverse=True)
    for val in coins:
        numberCoins += math.floor(remainingTotal / val)
        remainingTotal -= math.floor(remainingTotal / val) * val
        if remainingTotal == 0:
            return numberCoins
