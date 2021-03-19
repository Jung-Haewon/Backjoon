n = int(input())
ans = 1
for i in range(n):
    ans += 4 + 3 * i
print(ans%45678)
