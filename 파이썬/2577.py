a = int(input())
b = int(input())
c = int(input())
number = str(a * b * c)
for i in range(10):
    print(number.count(str(i)))
