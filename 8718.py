x, k = map(int, input().split())

ans = [k*0.5*0.5 + k*0.5 + k, k*0.5 + k + k*2, k + k*2 + k*4]
if ans[2] <= x:
    print(int(ans[2] * 1000))
elif ans[1] <= x:
    print(int(ans[1] * 1000))
elif ans[0] <= x:
    print(int(ans[0] * 1000))
else:
    print(0)
