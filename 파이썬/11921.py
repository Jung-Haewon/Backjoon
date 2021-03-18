import sys

n = int(sys.stdin.readline().rstrip())
ans = 0
for i in range(n):
    ans += int(sys.stdin.readline().rstrip())
    cnt += 1
print(cnt)
print(ans)
