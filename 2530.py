a, b, c = map(int, input().split())
d = int(input())
tmp = a * 3600 + b * 60 + c + d
print((tmp//3600)%24, (tmp//60)%60, tmp%60)
