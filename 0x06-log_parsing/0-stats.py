#!/usr/bin/python3
"""_summary_
"""
import sys


def afterTen(statCount, fileSize):
    """_summary_

    Args:
        statCount (_type_): _description_
        fileSize (_type_): _description_
    """
    print("File size: {}".format(fileSize))
    for key in sorted(statCount.keys()):
        if statCount[key] == 0:
            continue
        print("{}: {}".format(key, statCount[key]))


def log_parsing():
    """_summary_
    """
    count = 0
    size = 0
    counter = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
               "404": 0, "405": 0, "500": 0}

    try:
        for data in sys.stdin:
            count += 1
            temp = data.split(" ")
            try:
                statusCode = temp[-2]
                size += int(temp[-1])
                if statusCode in counter:
                    counter[statusCode] += 1
            except Exception:
                pass
            if count % 10 == 0:
                afterTen(counter, size)
        else:
            afterTen(counter, size)
    except (KeyboardInterrupt, SystemExit):
        afterTen(counter, size)
        raise


if __name__ == "__main__":
    log_parsing()
