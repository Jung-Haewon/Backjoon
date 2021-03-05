n = input()
cnt = n.count('10')

if cnt == 0:
    print(int(n[0])+int(n[1]))
elif cnt == 2:
    print(20)
else:
    tmp = n.find('10')
    if tmp == 0:
        print(int(n[:2])+int(n[2:]))
    else:
        print(int(n[:1])+int(n[1:]))
