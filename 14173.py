x = []
y = []
for i in range(2):
    tmp = list(map(int, input().split()))
    x += tmp[::2]
    y += tmp[1::2]
print(max(max(x)-min(x),max(y)-min(y))**2)
