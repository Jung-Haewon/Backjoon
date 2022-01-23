a, b = map(int, input().split())

if a == 0:
    print(0)
    print(0)
else:
    c = abs(a)
    d = abs(b)

    ans1 = c // d
    ans2 = c % d
    
    if a > 0 and b > 0:
        print(ans1)
        print(ans2)
    elif a > 0 and b < 0:
        print(-ans1)
        print(ans2)
    elif a < 0 and b > 0:
        ans1 = -ans1
        ans2 = -ans2
        if ans2 < 0:
            ans1 = ans1 - 1
            ans2 = ans2 + b
        print(ans1)
        print(ans2)
    else:
        ans2 = -ans2
        if ans2 < 0:
            ans1 = ans1 + 1
            ans2 = ans2 - b
        print(ans1)
        print(ans2)
