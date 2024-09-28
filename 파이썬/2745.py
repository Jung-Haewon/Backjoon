n, bStr = input().split()
b = int(bStr)

ans = 0

for i in range(1, len(n) + 1):
    if ord(n[-i]) < 58:
        ans += int(n[-i])*(b**(i-1))
    else:
        ans += (ord(n[-i])-55)*(b**(i-1))

print(ans)
