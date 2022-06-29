import sys
for i in range(3):
    cnt = int(sys.stdin.readline().rstrip())
    sum = 0
    for j in range(cnt):
        a = int(sys.stdin.readline().rstrip())
        sum += a
    if sum > 0:
        print('+')
    elif sum == 0:
        print(0)
    else:
        print('-')