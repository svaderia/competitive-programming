#!/usr/bin/env python
# @author = 53 68 79 61 6D 61 6C 
# date	  = 13/02/2019

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import sys

def input():
    # redefine input so that it works with both python2 and python3
    return sys.stdin.readline().rstrip()


def main():
    T = int(input())
    for _ in range(T):
        input()
        s = input()
        rone = 0
        total = 0
        for c in s[::-1]:
            if c == "1":
                total += (1 + rone)
                rone += 1
        print(total)


if __name__ == "__main__":
    main()
