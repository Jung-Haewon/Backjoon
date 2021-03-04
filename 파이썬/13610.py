n = 1
x, y = map(int, input().split())
while True:
    if (x*n)/y <= n-1:
        break
    n += 1
print(n)
