import sys
input = sys.stdin.readline

t = int(input().rstrip())
for _ in range(t):
    n = int(sys.stdin.readline().rstrip())
    a = [int(x) for x in sys.stdin.readline().rstrip().split()]

    factorMap = {
    }

    for i in a:
        factorMap[i] = 1

    results = []

    found = False

    minFactors = 999999999

    for prod in range(1, len(a)+1):
        found = False
        minFactors = 999999999
        if prod in factorMap:
            results.append(1)
            found = True
        
        if not found:
            for possibleFactor in range(1, int((prod ** 0.5) + 1)):
                if (prod % possibleFactor == 0):
                    if ((prod/possibleFactor in factorMap) and (possibleFactor in factorMap)):
                        if (factorMap[prod/possibleFactor] + factorMap[possibleFactor] < minFactors):
                            minFactors = factorMap[prod/possibleFactor] + factorMap[possibleFactor]
                        found = True
        if found and minFactors != 999999999:
            factorMap[prod] = minFactors
            results.append(minFactors)
        if not found:
            results.append(-1)

    for ans in results:
        print(ans, end = " ")
    print()
