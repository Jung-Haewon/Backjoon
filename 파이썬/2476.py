n = int(input())
ans = 0

for i in range(n):
    a = sorted(list(map(int, input().split())))

    if a.count(a[1]) == 3:
        tmp = 10000 + 1000 * a[1]
    elif a.count(a[1]) == 2:
        tmp = 1000 + 100 * a[1]
    else:
        tmp = 100 * a[2]

    if tmp > ans:
        ans = tmp

print(ans)
