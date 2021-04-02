import copy

def read_data(): #데이터 입력
    f = open("ballpark.inp", "r")
    ret = []
    n, m = map(int, f.readline().split())
    for i in range(n):
        ret.insert(0, list(map(int, f.readline().rstrip())))
    f.close()
    return n, m, ret

def print_data(cnt, ans): #데이터 출력
    f = open("ballpark.out", "w")
    f.write(str(cnt) + ' ' + str(len(ans))+'\n')
    for i in range(len(ans)):
        f.write(str(ans[i][0]) + ' ' + str(ans[i][1])+'\n')
    f.close()

def process(n, m, ret):
    array = list(ret)
    blank = [[1 for _ in range(m)] for _ in range(n)]
    cnt = 1
    while 1:
        array, tmp = possible(array, n, m, cnt, blank)
        if array == blank:
            break
        else:
            ans = tmp
        cnt += 1
    return cnt, ans

def possible(array, n, m, i, blank):
    nextArray = copy.deepcopy(blank)
    ans = []

    for p in range(m-i):
        for l in range(n-i):
            tmp = subPossible(array, p, l, i)
            nextArray[l][p] = tmp
            if tmp == 0:
                ans.append([p+1,l+1])
    
    return nextArray, ans

def subPossible(array, x, y, n):
    tmp = 0
    for i in range(2):
        for j in range(2):
            if array[y+i][x+j] == 1:
                tmp = 1
                if tmp == 1:
                    break
        if tmp == 1:
            break
    return tmp
    

n, m, ret = read_data()
cnt, ans = process(n, m, ret)
print_data(cnt, ans)
