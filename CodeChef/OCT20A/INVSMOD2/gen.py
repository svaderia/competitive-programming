import random

MAXN = 1000
test = 1000
print(test)
random.seed(0)

for _ in range(test):
    n = random.randint(0, MAXN)
    k = random.randint(0, n)
    print("{} {}".format(n, k))


