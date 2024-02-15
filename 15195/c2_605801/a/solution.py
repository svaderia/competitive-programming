
def main():
    chars = input()

    cc = {}
    for x in chars:
        if x not in cc:
            cc[x] = 0
        cc[x] += 1

    n = len(chars)
    # print(cc)

    ans = []
    if (n%2 == 0):
        for x in cc:
            if cc[x] % 2 != 0:
                print("NO SOLUTION")
                return
            ans.append(x * (cc[x] // 2))
        ans = ans + list(reversed(ans))
    else:
        odd = ''
        for x in cc:
            if cc[x] % 2 != 0:
                if odd == '':
                    odd = x
                else:
                    print("NO SOLUTION")
                    return
            ans.append(x * (cc[x] // 2))
        ans = ans + [odd] + list(reversed(ans))

    print("".join(ans))

if __name__ == "__main__":
    main()
