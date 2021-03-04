import math
n = int(input())
tmp = math.ceil(n/2)
if n % 2 == 0:
    print((tmp+1)**2)
else:
    print(tmp*(tmp+1))
