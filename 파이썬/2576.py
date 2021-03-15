a = []

for i in range(7):
    b = int(input())
    if b % 2 == 1:
        a.append(b)

if a == []:
    print(-1)
else:
    print(sum(a))
    print(min(a))
    
