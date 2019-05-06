#!/usr/bin/env python
# @author = 53 68 79 61 6D 61 6C 
# date	  = 03/05/2019

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import sys
from math import ceil
def input():
    # redefine input so that it works with both python2 and python3
    return sys.stdin.readline().rstrip()


def main():
    N, W, L1 = [int(x) for x in input().split()]
    
    H = list()
    for _ in range(N):
        H.append([int(x) for x in input().split()])
    
    L = list()

    for i in range(N):
        if(L1 <= H[i][0]):
            days = 0
        else:
            days = ceil((L1-H[i][0])/H[i][1])
        print(days, H[i][0], H[i][1])
        L.append((days, H[i][0], H[i][1]))
    
    sorted(L)



    ah = 0
    ar = 0
    pah = 0
    par = 0

    ans = -1

    if(W > L1):
        for i in range(N):
            pah = ah
            par = ar
            ah += L[i][1]
            ar += L[i][2]
            if(ah + ar*L[i][0] >= W):
                ans = ceil((W - pah)/par)
                print(ans)
                ans = min(ans, L[i][0])
                print(ans, i)
                break
    else:
        ans = L[0][0]
    
    if ans == -1 :
        ans = ceil((W - ah)/ar)

    print(ans) 

if __name__ == "__main__":
    main()
