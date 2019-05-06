#!/usr/bin/env python
# @author = 53 68 79 61 6D 61 6C 
# date	  = 15/02/2019

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
        s = input()
        count = dict()
        for char in s:
            if(char in count):
                count[char] += 1
            else:
                count[char] = 1
            
        values = sorted(count.values(), reverse=True)

        N =  len(s)
        total_list = []
        for i in range(1, min(26, N) + 1):
            if( N % i == 0):
                fin = int(N / i)
                total = 0
                for val in range(min(i, len(values))):
                    if(values[val] > fin):
                        total += (values[val] - fin)
                
                for val in values[min(i, len(values)):]:
                    total += val

                total_list.append(total)

        print(min(total_list))
if __name__ == "__main__":
    main()
