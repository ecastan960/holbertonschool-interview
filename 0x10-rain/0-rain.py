#!/usr/bin/python3
"""_summary_
"""


def rain(walls):
  """_summary_

  Args:
      walls (_type_): _description_

  Returns:
      _type_: _description_
  """
  total = 0
  size = len(walls)

  for i in range(1, size - 1):
      left = walls[i]
      for j in range(i):
          left = max(left, walls[j])
      right = walls[i]
      for j in range(i + 1, size):
          right = max(right, walls[j])
      total = total + (min(left, right) - walls[i])
  return total
