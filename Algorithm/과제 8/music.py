def read_data(): #데이터 입력
    f = open("music.inp", "r")
    match, mis, gap = map(int, f.readline().split())
    string = f.readline().rstrip()
    return string, match, mis, gap

def print_data(first, second, best): #데이터 출력
    f = open("music.out", "w")
    tmp = first + "\n" + second + "\n" + str(best)
    f.write(tmp)
    f.close()

def process(string, match, mis, gap):
    sub_str = []

    f = ""
    s = ""
    b = 0
    
    for i in range(1, len(string)-2):
        sub_str.append([string[:i],string[i:]])

    for i in sub_str:
        tmp_f, tmp_s, tmp_b = cal(i[0], i[1], match, mis, gap)
        if tmp_b > b:
            f = tmp_f
            s = tmp_s
            b = tmp_b
    
    return f, s, b

def cal(first, second, match, mis, gap):
    best = 0
    bLoc = [0,0]

    f_len = len(first) + 1
    s_len = len(second) + 1

    arr = [[0 for _ in range(f_len)]for _ in range(s_len)]

    for i in range(1, s_len):
        for j in range(1, f_len):
            tmp = arr[i-1][j-1] + [match, mis][first[j-1] != second[i-1]]
            arr[i][j] = max(tmp, arr[i][j-1] + gap, arr[i-1][j] + gap, 0)
            if arr[i][j] > best:
                best = arr[i][j]
                bLoc = [j-1, i-1]

    start = [bLoc[0], bLoc[1]]
    while True:
        if arr[start[1]-1][start[0]-1] != 0:
            start[0] -= 1
            start[1] -= 1
        elif arr[start[1]-1][start[0]] != 0:
            start[1] -= 1
        elif arr[start[1]][start[0]-1] != 0:
            start[0] -= 1
        else:
            break

    return (first[start[0]-1:bLoc[0]+1], second[start[1]-1:bLoc[1]+1], best)

string, match, mis, gap = read_data()
f, s, b = process(string, match, mis, gap)
print_data(f, s, b)
