import math
a, b, c = map(int, input().split())
if c != b:
    n = a / (c - b) + 1
else:
    n = 0

n = math.floor(n)
    
if n > 0:
    print(n)
else:
    print(-1)
