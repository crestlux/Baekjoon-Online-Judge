S = int(input())
ret = 0; i = 1
while True:
    if S < i:
        break
    else:
        S -= i
        i += 1
        ret += 1
print(ret)