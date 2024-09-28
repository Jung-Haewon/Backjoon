def diceMatch(a, b):
    aScore = 0
    bScore = 0

    for i in range(4):
        for j in range(4):
            if a[i] > b[j]:
                aScore += 1
            elif a[i] < b[j]:
                bScore += 1
                
    if aScore > bScore:
        return 1
    elif aScore == bScore:
        return 0
    else:
        return -1

for _ in range(int(input())):
    tmp = list(map(int, input().split()))
    a = tmp[:4]
    b = tmp[4:]
    aBitB = diceMatch(a, b)

    if aBitB == 0:
        print('no')
        continue

    isC = False

    for c1 in range(1, 11):
        for c2 in range(1, 11):
            for c3 in range(1, 11):
                for c4 in range(1, 11):
                    c = [c1, c2, c3, c4]
                    
                    cBitA = diceMatch(c, a)
                    cBitB = diceMatch(c, b)


                    if cBitA == 0 or cBitB == 0:
                        continue

                    if aBitB == 1:
                        if cBitA == 1 and cBitB == -1:
                            isC = True

                    if aBitB == -1:
                        if cBitA == -1 and cBitB == 1:
                            isC = True
                    
    if isC == True:
        print('yes')
    else:
        print('no')
