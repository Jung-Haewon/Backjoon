m = int(input())
n = [1, 0, 0]

for i in range(m):
    x, y = map(int, input().split())
    n[x-1], n[y-1] = n[y-1], n[x-1]

print(n.index(1)+1)
