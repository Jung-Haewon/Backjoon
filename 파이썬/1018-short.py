def inspect(a):
    n = []
    e = 'WBWBWBWB'
    f = 'BWBWBWBW'
    ans = [e+f+e+f+e+f+e+f,f+e+f+e+f+e+f+e]
    for x in range(2):
        b = len([0 for c in range(64) if ans[x][c] != a[c]])
        n.append(b)
    return min(n)

n,m=map(int,input().split())
board=[]
exec('board.append(input());'*n)

cnt = []
for i in range(n-7):
    for j in range(m-7):
        tmp = ''
        for x in range(8):
            tmp += board[i+x][j:j+8]
        cnt.append(inspect(tmp))

        
print(min(cnt))
