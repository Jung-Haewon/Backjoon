n = int(input())
group = []
for i in range(n):
    group.append(list(map(int, input().split())))

for i in range(n):
    cnt = 1
    for j in range(n):
        if group[i][0] < group[j][0] and group[i][1] < group[j][1]:
            cnt += 1
    print(cnt, end=' ')
