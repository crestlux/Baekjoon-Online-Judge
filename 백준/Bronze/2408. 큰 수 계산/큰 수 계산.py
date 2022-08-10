import sys
n = int(sys.stdin.readline().rstrip())
exp = ''
for i in range(n*2+1):
    input = sys.stdin.readline().rstrip()
    if input == "/":
        input = "//"
    exp += input
print(int(eval(exp)))