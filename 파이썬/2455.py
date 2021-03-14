ans = 0
tmp = 0
for i in range(3):
    n, m = map(int, input().split())
    tmp = tmp-n+m
    ans = max(ans, tmp)
print(ans)
