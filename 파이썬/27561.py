n = int(input())
cows = input()
idxies = list(map(int, (input().split())))

oIdx = 0
cnt = 0

if cows[0] == 'G':
    oIdx = cows.find('H')

    if 'H' not in cows[idxies[oIdx] : len(cows)]:
        for i in range(oIdx, 0, -1):
            if cows[i] == 'G' and idxies[i] > oIdx:
                cnt += 1

        if idxies[0] >= oIdx:
            cnt += 1
        elif cows.count('G') == cows[0 : idxies[0]].count('G'):
            cnt += 1    
else:
    oIdx = cows.find('G')

    if 'G' not in cows[idxies[oIdx] : len(cows)]:
        for i in range(oIdx, 0, -1):
            if cows[i] == 'H' and idxies[i] > oIdx:
                cnt += 1

        if idxies[0] >= oIdx:
            cnt += 1
        elif cows.count('H') == cows[0 : idxies[0]].count('H'):
            cnt += 1    
    
print(cnt)
