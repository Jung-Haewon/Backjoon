d, h, m = map(int, input().split())
start = 11*60*24 + 11*60 + 11
end = d*60*24 + h*60 + m
tmp = end - start
if tmp < 0:
    print(-1)
else:
    print(tmp)
