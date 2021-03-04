a = []
for i in range(int(input())):
    a.append(input())
    
b = list(a[0])

for i in a:
    for j in range(len(b)):
        if b[j] != i[j]:
            b[j] = '?'

c = ''.join(b)

print(c)
