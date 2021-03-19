input()
a = list(map(int, input().split()))

y = sum([(x//30 + 1) * 10 for x in a])
m = sum([(x//60 + 1) * 15 for x in a])

if y < m:
    print('Y', y)
elif m < y:
    print('M', m)
else:
    print('Y M', y)
