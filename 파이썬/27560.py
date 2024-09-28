n = int(input())
arr = list(map(int, input().split()))
cnt = [0 for _ in range(n)]
ans = ""

idx = 0

for i in arr:
    ans += 'R' + 'LR' * (int(i/2) - 1)
ans += 'L' * n

print(ans)
