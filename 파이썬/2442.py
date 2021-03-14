n = int(input())

for i, j in enumerate(range(1, n*2, 2)):
    print(' '*(n-i-1) + '*'*j)
