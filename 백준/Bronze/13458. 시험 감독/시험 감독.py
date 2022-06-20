import sys
import math
N = int(input())
a = list(map(int, sys.stdin.readline().split()))
b, c = map(int, sys.stdin.readline().split())
ret = 0
for i in a:
    i -= b
    if i < 0:
        i = 0
    ret += 1 + math.ceil(i/c)
print(ret)