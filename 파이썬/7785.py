n = int(input())
staff = set()

for _ in range(n):
    name, order = input().split()

    if order == 'enter':
        staff.add(name)
    else:
        staff.remove(name)

ans = list(staff)
ans.sort(reverse = True)
for name in ans:
    print(name)
