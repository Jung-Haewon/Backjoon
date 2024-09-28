import sys
print = sys.stdout.write

n, m, q = map(int, sys.stdin.readline().split())
arr = [[0 for _ in range(m)] for __ in range(n)]

for _ in range(q):
    o, l, v = map(int, sys.stdin.readline().split())

    if o == 1:
        for i in range(m):
            arr[l-1][i] += v
    else:
        for i in range(n):
            arr[i][l-1] += v

for i in range(n):
    for j in range(m):
        print(str(arr[i][j]) + ' ')
    print('\n')
