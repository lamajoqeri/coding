import sys
input = sys.stdin.readline
t = int(input().rstrip())

for _ in range(t):
    n, q = sys.stdin.readline().rstrip().split()
    n = int(n)
    q = int(q)
    a = [int(x) for x in sys.stdin.readline().rstrip().split()]
    b = [int(x) for x in sys.stdin.readline().rstrip().split()]
    l = []
    r = []
    for _ in range(q):
        ln, rn = sys.stdin.readline().rstrip().split()
        ln = int(ln)
        rn = int(rn)
        l.append(ln)
        r.append(rn)

    answers = []

    curMaxes = [0] * n
    curMax = 0
    for j in range(n-1, -1, -1):
        if a[j] > curMax:
            curMax = a[j]
        if b[j] > curMax:
            curMax = b[j] 
        curMaxes[j] = curMax
    
    cumMaxSum = []
    cumMaxSum.append(curMaxes[0])
    for i in range(1, len(curMaxes)):
        cumMaxSum.append(cumMaxSum[i-1] + curMaxes[i])
    


    for i in range(q):
        total = 0
        
        answers.append(cumMaxSum[r[i]-1] - cumMaxSum[l[i]-1] + curMaxes[l[i]-1])

    for ans in answers:
        print(ans, end = " ")
    print()
        

  
