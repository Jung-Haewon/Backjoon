n = int(input())
cows = list(map(int, input().split()))
cows.sort()
ans1 = 0
ans2 = 0

for i in range(n-1, -1, -1):
    tmp = cows[i] * (n - i)

    if tmp >= ans1:
        ans1 = tmp
        ans2 = cows[i]


print(ans1, ans2)
