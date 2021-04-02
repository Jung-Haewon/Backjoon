from collections import deque

def read_data(): #데이터 입력
    f = open("free.inp", "r")
    n = int(f.readline())
    ret = deque()
    for i in range(n):
        ret.appendleft(list(map(int, f.readline().split())))
    f.close()
    return ret

def print_data(data): #데이터 출력
    f = open("free.out", "w")
    f.write(data)
    f.close()

def process(arr):
    ans = cal(arr, 0)
    return str(ans[0]) + " " + str(ans[1])
        

def cal(arr, n):
    try:
        first = arr.popleft()
    except:
        return [arr[0][2], n + arr[0][1]-arr[0][0]+1]
    
    tmp = deque()
    isOverlap = False
    challenger = [0, 0]
    
    for b in arr:
        if first[0] > b[1] or first[1] < b[0]:
            tmp.append(b)
        else:
            isOverlap = True

    if len(tmp) != 0:
        this = cal(tmp, n + first[1]-first[0]+1)
        this[0] += first[2] - 10
    else:
        this = [first[2], n + first[1]-first[0]+1]

    if isOverlap == False:
        return this
    else:
        challenger = cal(arr, n)

    if this[0] == challenger[0]:
        return [this[0], min(this[1], challenger[1])]
    elif this[0] > challenger[0]:
        return this
    else:
        return challenger

print_data(process(read_data()))
