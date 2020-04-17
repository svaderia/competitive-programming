#!/usr/bin/env python3
# @author = svaderia
# date	  = 17/04/2020


def main():
    print("".join("." + i.lower() for i in input() if i.lower() not in "aeiouy"))

if __name__ == "__main__":
    main()
