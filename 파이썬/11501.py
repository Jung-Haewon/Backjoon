t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    best = 0
    ans = 0

    for i in range(n-1, -1, -1):
        if arr[i] > best:
            best = arr[i]

        ans += best - arr[i]

    print(ans)
