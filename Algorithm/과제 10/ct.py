def read_data(): #데이터 입력
    f = open("ct.inp", "r")
    n = int(f.readline())
    infor = []
    for i in range(4):
        infor.append(list(map(int, f.readline().split())))
    
    return n, infor

def print_data(arr, n): #데이터 출력
    f = open("ct.out", "w")

    for i in range(n):
        for j in range(n):
            if arr[i][j] == 0:
                f.write('-')
            else:
                f.write('B')
            if j != n-1:
                f.write(' ')
        f.write('\n')
    f.close()

def process(n, infor):
    arr = [[-1 for x in range(n)] for x in range(n)]

    while True:
        for i in range(n):
            tmp = 0
            for j in range(n):
                if arr[j][i] == 1 or arr[j][i] == -1:
                    tmp += 1
            if tmp == infor[0][i]:
                for j in range(n):
                    if arr[j][i] == -1:
                        arr[j][i] = 1

        for i in range(n):
            tmp = 0
            for j in range(n):
                if arr[j][i] == 1:
                    tmp += 1
            if tmp == infor[0][i]:
                for j in range(n):
                    if arr[j][i] == -1:
                        arr[j][i] = 0
                        
        for i in range(n):
            tmp = 0
            tmp += arr[i].count(1) + arr[i].count(-1)
            if tmp == infor[1][i]:
                for j in range(n):
                    if arr[i][j] == -1:
                        arr[i][j] = 1

        for i in range(n):
            tmp = 0
            tmp += arr[i].count(1)
            if tmp == infor[1][i]:
                for j in range(n):
                    if arr[i][j] == -1:
                        arr[i][j] = 0


        for i in range(2*n - 1):
            tmp1 = 0
            tmp2 = 0

            if i < n:
                start = n - i - 1
                tmp = 0
                while start < n:
                    if arr[start][tmp] == 1 or arr[start][tmp] == -1:
                        tmp1 += 1
                    if arr[start][tmp] == 1:
                        tmp2 += 1
                    start += 1
                    tmp += 1
                if tmp1 == infor[2][2*n - 1-i-1]:
                    start = n - i - 1
                    tmp = 0
                    while start < n:
                        if arr[start][tmp] == -1:
                            arr[start][tmp] = 1
                        start += 1
                        tmp += 1
                if tmp2 == infor[2][2*n - 1-i-1]:
                    start = n - i - 1
                    tmp = 0
                    while start < n:
                        if arr[start][tmp] == -1:
                            arr[start][tmp] = 0
                        start += 1
                        tmp += 1
            else:
                start = i - n + 1
                tmp = 0
                while start < n:
                    if arr[tmp][start] == 1 or arr[tmp][start] == -1:
                        tmp1 += 1
                    if arr[tmp][start] == 1:
                        tmp2 += 1
                    start += 1
                    tmp += 1
                if tmp1 == infor[2][2*n - 1-i-1]:
                    start = i - n + 1
                    tmp = 0
                    while start < n:
                        if arr[tmp][start] == -1:
                            arr[tmp][start] = 1
                        start += 1
                        tmp += 1
                if tmp2 == infor[2][2*n - 1-i-1]:
                    start = i - n + 1
                    tmp = 0
                    while start < n:
                        if arr[tmp][start] == -1:
                            arr[tmp][start] = 0
                        start += 1
                        tmp += 1

        for i in range(2*n - 1):
            tmp1 = 0
            tmp2 = 0
            if i < n:
                start = i
                tmp = 0
                while start >= 0:
                    if arr[tmp][start] == 1 or arr[tmp][start] == -1:
                        tmp1 += 1
                    if arr[tmp][start] == 1:
                        tmp2 += 1
                    start -= 1
                    tmp += 1
                if tmp1 == infor[3][i]:
                    while start >= 0:
                        if arr[tmp][start] == -1:
                            arr[tmp][start] = 1
                        start -= 1
                        tmp += 1
                if tmp2 == infor[3][i]:
                    while start >= 0:
                        if arr[tmp][start] == -1:
                            arr[tmp][start] = 0
                        start -= 1
                        tmp += 1
            else:
                start = i - n + 1
                tmp = n - 1
                while start < n:
                    if arr[start][tmp] == 1 or arr[start][tmp] == -1:
                        tmp1 += 1
                    if arr[start][tmp] == 1:
                        tmp2 += 1
                    start += 1
                    tmp -= 1
                if tmp1 == infor[3][i]:
                    while start < n:
                        if arr[start][tmp] == -1:
                            arr[start][tmp] = 1
                        start += 1
                        tmp -= 1
                if tmp2 == infor[3][i]:
                    while start < n:
                        if arr[start][tmp] == -1:
                            arr[start][tmp] = 0
                        start += 1
                        tmp -= 1
        tmp = 0
        for i in range(n):
            tmp += arr[i].count(-1)
        if tmp == 0:
            break

    return arr
        
n, infor = read_data()
arr = process(n, infor)
print_data(arr, n)
