import copy

def read_data(): #데이터 입력
    f = open("marathon.inp", "r")
    n, m = map(int, f.readline().split())
    edge = [[] for _ in range(26)]
    
    for i in range(m):
        tmp1, tmp2, tmp3 = f.readline().split()
        edge[ord(tmp1)-97].append([ord(tmp2), int(tmp3)])
        edge[ord(tmp2)-97].append([ord(tmp1), int(tmp3)])

    for i in range(26):
        edge[i].sort()

    return edge

def print_data(ans): #데이터 출력
    f = open("marathon.out", "w")
    f.write(str(len(ans)) + "\n")
    tmp = list(map(chr, ans))
    f.write(" ".join(tmp))
    f.close()
    
def main():
    edge = read_data()
    ans = [97]
    ans += backTracking(edge, [], 0, 0)
    print_data(ans)

def backTracking(edge, use, state, length):
    result = []
    for i in edge[state]:
        if i[0] not in use:
            tmp = length + i[1]
            if tmp < 42 and i[0] != 97:
                nextUse = copy.deepcopy(use)
                nextUse.append(i[0])
                tmpResult = backTracking(edge, nextUse, i[0]-97, tmp)
                if len(tmpResult) > len(result):
                    result = tmpResult
                    
            elif tmp == 42 and i[0] == 97:
                if len(use) > len(result):
                    result = use
    return result

main()
