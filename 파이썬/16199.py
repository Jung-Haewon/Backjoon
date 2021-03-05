a = list(map(int, input().split()))
b = list(map(int, input().split()))

n = b[0] - a[0]
if b[1] < a[1]:
    n -= 1
elif b[1] == a[1]:
    if b[2] < a[2]:
        n -= 1

print(n)
print(b[0]-a[0]+1)
print(b[0]-a[0])
