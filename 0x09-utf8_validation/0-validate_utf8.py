#!/usr/bin/python3
"""_summary_
"""


def validUTF8(data):
    """_summary_

    Args:
        data (_type_): _description_

    Returns:
        _type_: _description_
    """
    count = 0
    for c in data:
        if count == 0:
            if (c >> 5) == 0b110:
                count = 1
            elif (c >> 4) == 0b1110:
                count = 2
            elif (c >> 3) == 0b11110:
                count = 3
            elif (c >> 7):
                return False
        else:
            if (c >> 6) != 0b10:
                return False
            count -= 1
    return True