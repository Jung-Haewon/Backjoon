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

    zeroPrice = []
    for i in range(n):
        if infor[i][4] == 0:
            trigger = False
            for j in range(4):
                if infor[i][j] != 0:
                    trigger = True
                    break
            if trigger == True:    
                zeroPrice.append(i)

    tree = ""
    result = branch(target, infor, tree, n, best)
    ans = ""

    if result == "-1":
        ans = "0"
    else:
        for i in range(1, n+1):
            if i-1 in zeroPrice:
                ans += str(i) + " "
            elif result[i-1] == "1":
                ans += str(i) + " "

    return ans


def branch(target, infor, tree, n, best):
    #더이상 추가할 재료가 없을때
    #다시말해서, 트리가 완성되었을때 값을 반환합니다
    if len(tree) == n:
        current = cal(infor, tree, n)
        if match(target, current) == -1:
            return "-1"
        else:
            return tree

    #첫번째 bound 조건
    #지금까지의 값들로도 목표값을 달성했다면
    #더 이상 탐색을 하지 않고, 값을 반환합니다
    zeroTree = tree
    for i in range(n - len(tree)):
        zeroTree += "0"

    zero = cal(infor, zeroTree, n)
    if match(target, zero) == 1:
        return zeroTree

    #두번째 bound 조건
    #현재까지의 best와 비교해서, 무슨일이 있어도 현재값이 더 좋지않다면
    #더 이상 탐색을 하지 않고, 값을 반환합니다
    if zero[4] > best:
        return "-1"

    #세번째 bound 조건
    #앞으로 남은 재료를 모두 넣더라도, 목표값을 달성할 수 없다면
    #더 이상 탐색을 하지 않고, 값을 반환합니다
    failTree = tree
    for i in range(n - len(tree)):
        failTree += "1"

    fail = cal(infor, failTree, n)
    if match(target, fail) == -1:
        return "-1"

    #bound 되지도 않고, 아직 트리도 완성되지 않았을때
    #좀 더 탐색하는 과정입니다
    case1 = tree + "1"
    case2 = tree + "0"
    tree1 = branch(target, infor, case1, n, best)
    if tree1 != "-1":
        ans1 = cal(infor, tree1, n)
        if ans1[4] < best:
            best = ans1[4]
    tree2 = branch(target, infor, case2, n, best)

    #탐색한 트리중에서, 최적의 값을 추려내는 과정입니다
    if tree1 == "-1":
        return tree2
    elif tree2 == "-1":
        return tree1
    else:
        ans1 = cal(infor, tree1, n)
        ans2 = cal(infor, tree2, n)
        if ans1[4] < ans2[4]:
            return tree1
        elif ans1[4] > ans2[4]:
            return tree2
        else:
            if sum(ans1[:4]) >= sum(ans2[:4]):
                return tree1
            else:
                return tree2
            

def cal(infor, tree, n):
    ans = [0, 0, 0, 0, 0]
    for i in range(n):
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
