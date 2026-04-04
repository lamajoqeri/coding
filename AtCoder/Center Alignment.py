import sys
n = int(sys.stdin.readline().rstrip())

ss = []

maxlen = 0

for i in range(n):
    ss.append(sys.stdin.readline().rstrip())

for i in ss:
    if len(i) > maxlen:
        maxlen = len(i)

Ks = []

for i in ss:
    Ks.append(int((maxlen - len(i))/2))

for i in range(n):
    print(("." * Ks[i]), end="")
    print(ss[i], end="")
    print(("." * Ks[i]), end="")
    print()
    


