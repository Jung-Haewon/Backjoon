n, k = map(int, input().split())
ans = [x for x in range(1, n+1) if n % x == 0]
if k > len(ans):
    print(0)
else:
    print(ans[k-1])
