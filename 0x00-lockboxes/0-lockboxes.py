#!/usr/bin/python3
"""0. Lockboxes
    """


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened

    Args:
    boxes (list): list of locked boxes
    """
    keys = set()
    for newKey, box in enumerate(boxes):
        newKey = newKey + 1
        for key in box:
            if key < len(boxes):
                keys.add(key)
                keys.update(boxes[key])
            if len(keys) == len(boxes) or len(keys) == len(boxes) - 1:
                return True
        if newKey not in keys:
            return False
