n, m = map(int, input().split())
a = list(map(int, input().split()))
b = []

for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            b.append(a[i] + a[j] + a[k])

ans = [x for x in b if x <= m]
print(max(ans))
