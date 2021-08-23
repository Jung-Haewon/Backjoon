def read_data(): #데이터 입력
    f = open("food.inp", "r")
    n = int(f.readline())
    target = list(map(int, f.readline().split()))
    infor = []
    for i in range(n):
        infor.append(list(map(int, f.readline().split())))
    return n, target, infor

def print_data(ans): #데이터 출력
    f = open("food.out", "w")
    f.write(ans)
    f.close()

def process(n, target, infor):
    best = 0
    for i in range(n):
        best += infor[i][4]
        
    result = branch(target, infor, "", n, best)
    ans = ""

    if result[2] == "-1":
        return "0"
    else:
        for i in range(1, n+1):
            if result[2][i-1] == "1":
                ans += str(i) + " "

    return ans


def branch(target, infor, tree, n, best):
    #더이상 추가할 재료가 없을때
    if len(tree) == n:
        current = cal(infor, tree)
        if match(target, current) == -1:
            return [-1, -1, "-1"]
        else:
            return [current[4], sum(current[:4]), tree]

    #첫번째 bound 조건
    #앞으로 무슨일이 있어도, 최소조건을 만족 못할경우 bound 시킨
    tmpTree = tree
    for i in range(n - len(tree)):
        tmpTree += "1"

    tmp = cal(infor, tmpTree)
    if match(target, tmp) == -1:
            return [-1, -1, "-1"]

    #두번째 bound 조건
    #앞으로 무슨일이 있어도, 기존의 최저가격을 넘어버릴 경우
    tmpTree = tree
    for i in range(n - len(tree)):
        tmpTree += "0"

    tmp = 0
    for i in range(n):
        if tmpTree[i] == 1:
            tmp += infor[i][4]
    if tmp >= best:
        return [-1, -1, "-1"]

    #세번째 bound 조건
    #이미 조건을 넘겼을때, 바로 반환해버림
    tmp = cal(infor, tmpTree)
    if match(target, tmp) == 1:
        return [tmp[4], sum(tmp[:4]), tmpTree]

        
    #bound 되지 않았을때, 아래의 과정을 수행한
    case1 = branch(target, infor, tree + "1", n, best)
    if case1[0] < best:
        best = case1[0]
    case2 = branch(target, infor, tree + "0", n, best)
    if case2[0] < best:
        best = case2[0]

    if case1[0] != -1 and case2[0] != -1:
        if case1[0] == case2[0]:
            if case1[1] < case2[1]:
                return case2
            return case1
        elif case1[0] <= case2[0]:
            return case1
        else:
            return case2
    elif case1[0] == -1 and case2[0] == -1:
        return case1
    elif case1[0] != -1:
        return case1
    else:
        return case2
    

def cal(infor, tree):
    ans = [0, 0, 0, 0, 0]
    for i in range(len(tree)):
        if tree[i] == "1":
            for j in range(5):
                ans[j] += infor[i][j]
    return ans

def match(target, current):
    for i in range(4):
        if target[i] > current[i]:
            return -1
    return 1
        


n, target, infor = read_data()
ans = process(n, target, infor)
print_data(ans)
