a = int(input())
b = int(input())
c = int(input())
d = int(input())
p = int(input())

x = p * a
y = b + max(0, p-c) * d
print(min(x,y))
