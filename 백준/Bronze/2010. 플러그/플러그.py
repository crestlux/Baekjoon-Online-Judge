from sys import stdin
N = int(stdin.readline())
sum = 0
for i in range(N):
    k = int(stdin.readline())
    sum += k
print(sum - (N-1))