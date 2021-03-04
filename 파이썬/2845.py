l, p = map(int, input().split())
b = list(map(int, input().split()))
a = [str(x - l*p) for x in b]
print(' '.join(a))
