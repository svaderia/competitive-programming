#!/usr/bin/env python
# @author = 53 68 79 61 6D 61 6C 
# date	  = 02/03/2019

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
from pprint import pprint
import sys
from itertools import combinations

def input():
    # redefine input so that it works with both python2 and python3
    return sys.stdin.readline().rstrip()


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        d = dict()
        dkon = dict()
        vow = ['a', 'e', 'i', 'o', 'u']
        vowels = set(vow)
        s = 0
        for x in vow:
            d[x] = set()
        for i in range(1, 6):
            comb = combinations(vow, i)
            for ele in list(comb):
                dkon[ele] = 0
        for i in range(N):
            temp = set(input())
            dkon[tuple(sorted(temp))] += 1
            for c in temp:
                d[c].add(i)

        d2 = dict()
        d2[tuple(sorted(set([])))] = N - 1
        for i in range(1, 6):
            comb = combinations(vow, i)
            for ele in list(comb):
                every = set(range(N))
                for x in ele:
                    every = every.intersection(d[x])
                d2[ele] = len(every)

        for ele in dkon:
            if(dkon[ele] > 0):
                yeah = vowels.difference(set(ele))
                s += dkon[ele] * d2[tuple(sorted(yeah))]

        print(int(s/2))

if __name__ == "__main__":
    main()
