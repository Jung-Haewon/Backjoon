n, m = map(int, input().split())
s = set()
q = list()

for _ in range(n):
    s.add(input())

for _ in range(m):
    q.append(input())

cnt = 0
for i in q:
    if i in s:
        cnt += 1

print(cnt)
