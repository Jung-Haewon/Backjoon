for i in range(int(input())):
    a, b = map(int, input().split())
    a = a%10
    b = b%4
    if b == 0:
        b = 4
    ans = (a ** b)%10
    if ans == 0:
        ans = 10
    print(ans)
