x = int(input())
n = int(input())

for i in range(n):
    a, b = map(int, input().split())
    x -= a*b

if 0 == x:
    print("Yes")
else:
    print("No")
