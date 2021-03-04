n = int(input())
i = 0
tmp = 666
while 1:
    if '666' in str(tmp):
        i += 1
        if i == n:
            print(tmp)
            break
    tmp += 1
