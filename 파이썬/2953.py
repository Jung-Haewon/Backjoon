a=[]
for i in range(5):
    a.append(sum(map(int,input().split())))
b=max(a)
print(a.index(b)+1,b)
