#!/usr/bin/python3
"""_summary_

Returns:
    _type_: _description_
"""
from sys import argv, exit

if __name__ == "__main__":

    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    queens = argv[1]

    try:
        queens = int(queens)
    except ValueError:
        print("N must be a number")
        exit(1)

    if queens < 4:
        print("N must be at least 4")
        exit(1)

    answer = []

    def nqueens(row, queens, answer):
        """_summary_

        Args:
            row (_type_): _description_
            queens (_type_): _description_
            answer (_type_): _description_
        """
        if (row == queens):
            print(answer)
        else:
            for col in range(queens):
                pos = [row, col]
                if valid(answer, pos):
                    answer.append(pos)
                    nqueens(row + 1, queens, answer)
                    answer.remove(pos)

    def valid(answer, position):
        """_summary_

        Args:
            answer (_type_): _description_
            position (_type_): _description_

        Returns:
            _type_: _description_
        """
        for queen in answer:
            if queen[1] == position[1] or \
                (queen[0] - queen[1]) == (position[0] - position[1]) or \
                    (queen[0] + queen[1]) == (position[0] + position[1]):
                return False
        return True

    nqueens(0, queens, answer)
