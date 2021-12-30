arr = list(map(int, input().split()))
answer = 0

for x in range(min(arr), 1000001):
    cnt = 0
    for y in range(5):
        if x % arr[y] == 0:
            cnt = cnt + 1
    if cnt >= 3:
        answer = x
        break

print(answer)
