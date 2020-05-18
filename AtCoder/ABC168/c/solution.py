import math

A, B, H, M = [int(x) for x in input().split()]

total_time_sec = H * 60 * 60 + M * 60

t1 = (2 * math.pi * total_time_sec) / (12 * 60 * 60)
t2 = (2 * math.pi * total_time_sec) / (60 * 60)

dist = math.sqrt(A*A + B*B - 2 * A * B * math.cos(t1 - t2))
print(dist)