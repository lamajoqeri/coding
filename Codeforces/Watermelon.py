import sys
input = sys.stdin.readline

n = int(input())


if n % 2 == 0:
    if n > 2:
        print("YES")
    else:
        print("NO")
else:
    print("NO")