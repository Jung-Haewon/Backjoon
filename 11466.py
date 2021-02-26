a = sorted(list(map(int, input().split())))
ans1 = a[0]/2
ans2 = a[1]/3
ans3 = a[0]
if ans2 > a[0]:
    ans2 = 0
if ans3 * 3 > a[1]:
    ans3 = 0
print('{:.4f}'.format(max(ans1, ans2, ans3)))
