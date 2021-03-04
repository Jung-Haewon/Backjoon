A = int(input())
B = int(input())

tmp = B % 100

hundred = B//100
ten = tmp//10
one = B%10

print(A*one)
print(A*ten)
print(A*hundred)
print(A*B)
