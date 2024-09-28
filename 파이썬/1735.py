def gcd(a, b):
    gcdList = [a, b]
    gcdList.sort()

    while gcdList[0] != 0:
       tmp = gcdList[1] - gcdList[0]
       gcdList = [gcdList[0], tmp]
       gcdList.sort()

    return gcdList[1]

a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())

a3 = a1 * b2 + a2 * b1
b3 = b1 * b2

a4 = a3 / gcd(a3, b3)
b4 = b3 / gcd(a3, b3)


print(int(a4), int(b4))
