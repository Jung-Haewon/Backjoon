import math

def starPrint(n, a):
    tmp = 3**n
    ans = range(int(tmp/3), int(2*tmp/3))
    b = [x for x in range(len(a)) if x%tmp in ans]
    for i in b:
        for j in b:
            a[i][j] = ' '
    n -= 1
    if n != 0:
        return starPrint(n, a)
    else:
        return a


n = int(input())
a = [['*' for col in range(n)] for row in range(n)]
b = starPrint(int(round(math.log(n, 3))), a)

tmp = ''
for i in b:
    tmp += ''.join(i) + '\n'

print(tmp)
