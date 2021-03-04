import math
n, h, w = map(int, input().split())
tmp = (n**2 / (h**2 + w**2))**0.5
print(math.floor(tmp*h), math.floor(tmp*w))
