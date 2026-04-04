import sys
import bisect

input = sys.stdin.readline
t = int(input().rstrip())
 
for _ in range(t):
    n = sys.stdin.readline().rstrip()
    n = int(n)
    
    a = [int(x) for x in sys.stdin.readline().rstrip().split()]
    b = [int(x) for x in sys.stdin.readline().rstrip().split()]
 
    answers = []

    cumMonsters = [0] * len(b)
    cumMonsters[0] = b[0]
    for i in range(1, len(b)):
        cumMonsters[i] = cumMonsters[i-1] + b[i]

    #print(cumMonsters)
    
    sortedSwords = sorted(a, reverse=True)

    '''totalStrength = 0
    swordStrengths = {

    }
    for i in range(len(sortedSwords)):
        totalStrength += 1
        swordStrengths[sortedSwords[i]] = totalStrength
'''
    maxkey = 0
    '''
    pairs = [[]]

    monsterPointer = 0
    for key in swordStrengths:
        while monsterPointer < len(cumMonsters):
            if cumMonsters[monsterPointer] <= swordStrengths[key]:
                monsterPointer += 1
            else:
                break
        pairs.append([key, monsterPointer])
'''
    pairs = [[]]

    swordBudget = 0
    monsterBudget = 0

    monsterPointer = 0      

    for i in range(len(sortedSwords)):
        while monsterPointer < len(cumMonsters):
            if cumMonsters[monsterPointer] <= i+1:
                monsterPointer += 1
            else:
                break
        pairs.append([sortedSwords[i], monsterPointer])

    #print(pairs)


    #print(pairs)
    for pair in range(1, len(pairs)):
        if (pairs[pair][0] * pairs[pair][1] > maxkey):
            maxkey = (pairs[pair][0] * pairs[pair][1])

    print(maxkey)
