def read_data(): #데이터 입력
    f = open("ballpark.inp", "r")
    n, m = map(int, f.readline().split())
    ret = [[] for _ in range(n)]
    for i in range(n):
        ret[n-i-1] = list(map(int, f.readline().rstrip()))
    f.close()
    return n, m, ret

def print_data(cnt, ans, big): #데이터 출력
    f = open("ballpark.out", "w")
    f.write(str(big) + ' ' + str(cnt)+'\n')
    for i in range(cnt):
        f.write(str(ans[i][0]+1) + ' ' + str(ans[i][1]+1) + '\n')
    f.close()

def process(n, m, array):
    default = [[min(m-a, n-b) for a in range(m)] for b in range(n)]
    
    for i in range(n):
        for j in range(m):
            if array[i][j] == 1:
                default[i][j] = 0

    cnt = 0
    ans = []
    big = 0
    for i in range(n-2,-1,-1):
        for j in range(m-2,-1,-1):
            if default[i][j] != 0:
                default[i][j] = min(default[i][j+1], default[i+1][j], default[i+1][j+1]) + 1
            if big < default[i][j]:
                big = default[i][j]
                cnt = 1
                ans = [[j,i]]
            elif big == default[i][j]:
                cnt += 1
                ans.append([j,i])

    return cnt, sorted(ans), big
                    

    

n, m, ret = read_data()
cnt, ans, big = process(n, m, ret)
print_data(cnt, ans, big)
