x = int(input())

t = 1
i = 1

while t + i <= x:
    t += i
    i += 1

t = x - t

if i % 2 != 0:
    a = i - t
    b = 1 + t
else:
    b = i - t
    a = 1 + t

print(a, '/', b, sep = "")
