a=[]
exec("a.append(input().split())\n"*int(input()))
for i in a:
    c=1
    for j in a:
        if i[0]<j[0]and i[1]<j[1]:
            c+=1
    print(c,end=' ')
