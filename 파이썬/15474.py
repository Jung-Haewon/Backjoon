n, a, b, c, d = map(int, input().split())
print(min(((n+a-1)//a)*b, ((n+c-1)//c)*d))

