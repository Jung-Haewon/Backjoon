import heapq

que = []
n = int(input())

for _ in range(n):
    heapq.heappush(que, int(input()))

ans = 0
while True:
    a = heapq.heappop(que)
    if len(que) == 0:
        break
    b = heapq.heappop(que)
    ans += a + b
    heapq.heappush(que, a + b)

print(ans)
