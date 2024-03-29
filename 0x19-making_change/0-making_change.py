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

    if len(coins) == 0:
        return -1
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    for val in coins:
        if val > remainingTotal:
            continue
        numberCoins += math.floor(remainingTotal / val)
        remainingTotal -= math.floor(remainingTotal / val) * val
        if remainingTotal == 0:
            return numberCoins
    return -1
