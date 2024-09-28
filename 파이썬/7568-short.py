n = int(input())
a=[]
exec("a.append(list(map(int,input().split())))\n"*n)
for i in a:
    c=1
    for j in a:
        if i[0]<j[0]and i[1]<j[1]:
            c+=1
    print(c,end=' ')
