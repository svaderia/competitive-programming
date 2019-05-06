#!/usr/bin/env python
# @author = 53 68 79 61 6D 61 6C 
# date	  = 23/02/2019

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import sys
import math
def input():
    # redefine input so that it works with both python2 and python3
    return sys.stdin.readline().rstrip()


def main():
    T = int(input())

    for _ in range(T):
        A = int(input())
        temp = math.log2(A)
        temp = math.ceil(temp)
        D2 = int( temp)
        
        i = D2
        k1 = i*A + 1
        k2 = 2 ** i
        while(True):
            if(k1 <= k2):
                break
            i+=1
            k1 += A
            k2 *= 2
        D1 = i - 1

        print("{} {}".format(D1, D2))

    

if __name__ == "__main__":
    main()
