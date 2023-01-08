#!/usr/bin/python3
"""_summary_
"""


def isPrime(n, i):
    """_summary_

    Args:
        n (_type_): _description_
        i (_type_): _description_

    Returns:
        _type_: _description_
    """
    if (n == 0 or n == 1):
        return False

    if (n == i):
        return True

    if (n % i == 0):
        return False

    i += 1

    return isPrime(n, i)


def isWinner(x, nums):
    """_summary_

    Args:
        x (_type_): _description_
        nums (_type_): _description_

    Returns:
        _type_: _description_
    """
    maria = 0
    ben = 0
    turn = 'Maria'
    winner = None
    if (x <= 0 or len(nums) == 0):
        return winner
    for r in range(x):
        for n in range(nums[r] + 1):
            if (nums[r] < 1):
                winner = None
                break
            if (nums[r] == 1):
                if(turn == 'Maria'):
                    maria += 1
                    turn = 'Ben'
                else:
                    ben += 1
                    turn = 'Maria'
                break
            if (nums[r] == 2):
                if(turn == 'Maria'):
                    ben += 1
                    turn = 'Ben'
                else:
                    maria += 1
                    turn = 'Maria'
                break
            if (nums[r] > 2 and n >= 2):
                if(isPrime(n, 2)):
                    if(turn == 'Maria'):
                        turn = 'Ben'
                    else:
                        turn = 'Maria'
            if (n == nums[r]):
                if(turn == 'Maria'):
                    ben += 1
                else:
                    maria += 1
    if (ben > maria):
        return 'Maria'
    elif (maria > ben):
        return 'Ben'
    else:
        return 'Ben'
