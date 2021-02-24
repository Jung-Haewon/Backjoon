import math
l = int(input())
a = int(input())
b = int(input())
c = int(input())
d = int(input())
kor = math.ceil(a/c)
mat = math.ceil(b/d)
print(l - max(kor, mat))
