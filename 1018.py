def inspect(a):
    n = []
    tmp = ['W', 'B']
    
    for z in range(2):
        b = 0
        for x in range(8):
            for y in range(8):
                if (x%2 == 0 and y%2 == 0) or (x%2 == 1 and y%2 == 1):
                    if a[x][y] != tmp[z]:
                        b += 1
                else:
                    if a[x][y] != tmp[(z+1)%2]:
                        b += 1
        n.append(b)
    return min(n)

n, m = map(int, input().split())
board = []
exec('board.append(input());'*n)

cnt = []
for i in range(n-7):
    for j in range(m-7):
        tmp = []
        for x in range(8):
            tmp.append(board[i+x][j:j+8])
        cnt.append(inspect(tmp))

        
print(min(cnt))
