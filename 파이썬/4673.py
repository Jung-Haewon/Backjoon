def d(a):
    if a >= 1000:
        n = 4
    elif a >= 100:
        n = 3
    elif a >= 10:
        n = 2
    else:
        n = 1

    ans = a
    string = str(a)
    for i in range(n):
        ans += int(string[i])

    return ans

b = list(range(1, 10000))

for i in range(1, 10000):
    tmp = d(i)
    if tmp in b:
        b.remove(tmp)
        
for i in b:
    print(i)


        
