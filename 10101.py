a = []
for i in range(3):
    a.append(int(input()))
a.sort()

if sum(a) == 180:
    if a.count(a[0]) == 3:
        print('Equilateral')
    elif a.count(a[1]) == 2:
        print('Isosceles')
    else:
        print('Scalene')
else:
    print('Error')
