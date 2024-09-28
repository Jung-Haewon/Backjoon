def gcd(a, b):
    gcdList = [a, b]
    gcdList.sort()

    while gcdList[0] != 0:
       tmp = gcdList[1] - gcdList[0]
       gcdList = [gcdList[0], tmp]
       gcdList.sort()

    return gcdList[1]
    

a, b = map(int, input().split())

ans = a * b / gcd(a, b)
print(int(ans))
