#!/usr/bin/env python
# @author = 53 68 79 61 6D 61 6C 
# date	  = 12/02/2019

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import sys

def input():
    # redefine input so that it works with both python2 and python3
    return sys.stdin.readline().rstrip()


def main():
    T =  int(input());
    a = set()
    for _ in range(T):
        N = int(input())
        a = set(input())
        for _ in range(N-1):
            b = set(input())
            a = a.intersection(b)
        print(len(a))


if __name__ == "__main__":
    main()
