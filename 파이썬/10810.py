n, m = map(int, input().split())

basket = [ 0 for _ in range(n)]

for _ in range(m):
    i, j, k = map(int, input().split())
    
    for index in range(i-1, j):
        basket[index] = k

ans = ""
for num in basket:
    ans += str(num) + " "

print(ans)
