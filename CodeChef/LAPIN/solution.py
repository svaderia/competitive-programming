#!/usr/bin/env python
# @author = 53 68 79 61 6D 61 6C 
# date	  = 13/02/2019

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import sys
import math
from pprint import pprint

def input():
    # redefine input so that it works with both python2 and python3
    return sys.stdin.readline().rstrip()


def main():
    T = int(input())
    for _ in range(T):
        s = input()
        mid = int(math.ceil(len(s) / 2))
        count = dict()
        for c in "qwertyuiopasdfghjklzxcvbnm":
            count[c] = 0

        for i, char in enumerate(s):
            if( i > mid - 1 ):
                count[char] -= 1
            else:
                count[char] += 1

        if(len(s) % 2 != 0):
            count[s[mid - 1 ]] -= 1

        ans = "YES"
        for item in count:
            if(count[item] != 0):
                ans = "NO"
        
        # pprint(count)
        print(ans)

if __name__ == "__main__":
    main()
