n = int(input())
ans = 0
for i in range(1, n+1):
    ans += i*(i+1)+sum(range(1, i+1))
print(ans)
