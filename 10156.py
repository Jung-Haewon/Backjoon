k, n, m = map(int, input().split())
tmp = k*n - m
if tmp <= 0:
    print(0)
else:
    print(tmp)
