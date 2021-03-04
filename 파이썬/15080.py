a=list(map(int, input().split(' : ')))
b=list(map(int, input().split(' : ')))
ans=(b[0]-a[0])*3600+(b[1]-a[1])*60+b[2]-a[2]
if ans < 0:
    print(ans+3600*24)
else:
    print(ans)
