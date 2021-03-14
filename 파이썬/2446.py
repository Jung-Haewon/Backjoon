n = int(input())

for i, j in enumerate(range(n*2-1, 1, -2)):
    print(' '*i + '*'*j)

for i, j in enumerate(range(1, n*2, 2)):
    print(' '*(n-i-1) + '*'*j)
    
