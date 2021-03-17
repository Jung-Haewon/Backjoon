import math

def read_data(): #데이터 입력
    f = open("station.inp", "r")
    ret = []
    for i in range(4):
        ret.append(list(map(int, f.readline().split())))
    f.close()
    return ret

def print_data(data): #데이터 출력
    f = open("station.out", "w")
    f.write(data)
    f.close()

def process(ret): #문제 해결
    a, b, c, d = ret

    for i in range(100):
        p, q = middle(a, b), middle(c, d)
        ans = length(p, q)

        #선분 s1위의 점 a, p, b와 s2위의 점 d, q, c을 각각의 거리(9가지 케이스)를 통해 문제를 해결한다.
        #분할정복 + Steepest hill climbing 알고리즘을 이용했습니다.
        tmp = min(length(a, d), length(a, q), length(a, c), length(b, d), length(b, q), length(b, c), length(p, d), length(p, q), length(p, c))

        if tmp == length(p, d):
            a = middle(a, p)
            b = middle(p, b)
            c = q
        elif tmp == length(p, q):
            a = middle(a, p)
            b = middle(p, b)
            c = middle(c, q)
            d = middle(q, d)
        elif tmp == length(p, c):
            a = middle(a, p)
            b = middle(p, b)
            d = q
        elif tmp == length(a, d):
            b = p
            c = q
        elif tmp == length(a, q):
            b = p
            c = middle(c, q)
            d = middle(q, d)
        elif tmp == length(a, c):
            b = p
            d = q
        elif tmp == length(b, d):
            a = p
            c = q
        elif tmp == length(b, q):
            a = p
            c = middle(c, q)
            d = middle(q, d)
        elif tmp == length(b, c):
            a = p
            d = q
            
    print(ans)
    return str(math.ceil(ans))

def length(a, b): #두 삼차원 벡터 사이의 거리를 반환
    return ((a[0]-b[0])**2 + (a[1]-b[1])**2 + (a[2]-b[2])**2)**.5

def middle(a, b): #두 삼차원 벡터 사이의 중간값을 반환
    return [(a[0]+b[0])/2, (a[1]+b[1])/2, (a[2]+b[2])/2]


ret = read_data()
ans = process(ret)
print_data(ans)
