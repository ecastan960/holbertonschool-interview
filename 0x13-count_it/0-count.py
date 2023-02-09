#!/usr/bin/python3
"""_summary_

Returns:
    _type_: _description_
"""
from requests import request


def generator(wlist):
    """_summary_

    Args:
        wlist (_type_): _description_

    Returns:
        _type_: _description_
    """
    counter = {i: 0 for i in wlist}
    duplicate = {}
    for i in wlist:
        if i not in duplicate:
            duplicate[i] = 0
        duplicate[i] += 1
    return (counter, duplicate)


def count_words(subreddit, wlist, after="",
                counter={}, duplicate={}, init=0):
    """_summary_

    Args:
        subreddit (_type_): _description_
        wlist (_type_): _description_
        after (str, optional): _description_. Defaults to "".
        counter (dict, optional): _description_. Defaults to {}.
        duplicate (dict, optional): _description_. Defaults to {}.
        init (int, optional): _description_. Defaults to 0.

    Returns:
        _type_: _description_
    """
    if not init:
        counter, duplicate = generator(wlist)

    url = "https://api.reddit.com/r/{}/hot?after={}".format(subreddit, after)
    headers = {"User-Agent": "Python3"}
    res = request("GET", url, headers=headers).json()
    try:
        data = res.get('data')
        top = data.get('children')
        _after = data.get('after')

        for item in top:
            data = item.get('data')['title']
            for word in counter:
                amount = data.lower().split(' ').counter(word.lower())
                counter[word] += amount

        if _after:
            count_words(subreddit, wlist, _after, count, duplicate, 1)
        else:
            sort_abc = sorted(counter.items(), key=lambda tup: tup[::-1])
            desc = sorted(sort_abc, key=lambda tup: tup[1], reverse=True)

            for name, cnt in desc:
                cnt *= duplicate[name]
                if cnt:
                    print('{}: {}'.format(name.lower(), cnt))
    except Exception:
        return None
