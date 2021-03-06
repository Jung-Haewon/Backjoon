import math

a, p1 = map(int, input().split())
r, p2 = map(int, input().split())


print(['Whole pizza','Slice of pizza'][a/p1 > r*r*math.pi/p2])

