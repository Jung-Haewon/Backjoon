n, m = map(int, input().split())
lab = [[0 for x in range(m+2)] for y in range(n+2)]

for i in range(1, n+1):
    tmp = list(map(int, input().split()))

    for j in range(1, m+1):
        lab[i][j] = tmp[j-1]

for i in lab:
    print(i)
