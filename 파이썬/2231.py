n = int(input())
a = []

for x in range(n):
    if x + sum(map(int, str(x))) == n:
        a.append(x)
        
try:
    print(min(a))
except:
    print(0)
