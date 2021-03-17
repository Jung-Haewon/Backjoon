import math

def main():
    ret = read_data()
    ans = process(ret)
    print_data(ans)

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
    p = a
    q = c
    ans = length(p, q)
    
    for i in range(100):
        if i % 2 == 0:
            q = short(p, c, d)
        else:
            p = short(q, a, b)

        tmp = length(p, q)
        if tmp < ans:
            ans = tmp

    if ans - math.floor(ans) < 0.00000000001:
        ans = math.floor(ans)
        
    return str(math.ceil(ans))

def length(a, b): #두 삼차원 벡터 사이의 거리를 반환
    return ((a[0]-b[0])**2 + (a[1]-b[1])**2 + (a[2]-b[2])**2)**.5

def middle(a, b): #두 삼차원 벡터 사이의 중간값을 반환
    return [(a[0]+b[0])/2, (a[1]+b[1])/2, (a[2]+b[2])/2]

def short(a, c, d): #점 a와 선분 c-d 사이에서 가장 짧은 거리에 있는 점을 반환
    front = c
    end = d

    for i in range(100):
        point = middle(front, end)
        
        if length(a, front) < length(a, end):
            end = point
        elif length(a, front) > length(a, end):
            front = point
        else:
            break
        
    return point
    
main()
