def read_data(): #데이터 입력
    f = open("jug.inp", "r")
    s = list(map(int, f.readline().split()))
    n = []
    for i in range(10):
        n.append(int(f.readline().rstrip()))
    f.close()
    return s, n

def print_data(data): #데이터 출력
    f = open("jug.out", "w")
    for i in data:
        f.write(['F','S'][i] + "\n")
    f.close()

def process(s, n):
    result = []

    for i in n:
        result.append(choice(s, i, 3, 0, 0, False))

    return result

def choice(s, ball, ignore, first, second, turn):
    '''
    매개변수 설명

    s : s1, s2, s3의 값
    ball : 현재 남아있는 공의 개수
    ignore : s1, s2, s3중 어느 숫자를 무시할지 결정, 3이 주어지면 셋다 사용 가능, 4가 주어지면 pass 사용 불가능
    first, second : First와 Second 각각이 pass를 사용했는지를 검사
    turn : 현재 First의 차례인지, Second의 차례인지를 각각 False, True로 결정
    '''
    ans = []
    for i in range(3):
        if i != ignore:
            if ball - s[i] < 0:
                ans.append(not turn)
            else:
                ans.append(choice(s, ball - s[i], i, first, second, not turn))

    if turn == 0 and first == 0 and ignore != 4:
        first = 1
        ans.append(choice(s, ball, 4, first, second, not turn))
    elif turn == 1 and second == 0 and ignore != 4:
        second = 1
        ans.append(choice(s, ball, 4, first, second, not turn))

    if turn in ans:
        return turn
    else:
        return not turn
    
s, n = read_data()
result = process(s, n)
print_data(result)
