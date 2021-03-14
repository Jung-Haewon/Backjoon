n = int(input())

a = [0,1]

if n > 2:
    for i in range(n-1):
        tmp = a[1]
        a[1] += a[0]
        a[0] = tmp
    print(a[1])
else:
    print([0,1,1][n])
