n = int(input())
arr = [0 for _ in range(200001)]

for _ in range(n):
    s, t = map(int, input().split())

    for i in range(s, t):
        arr[i] += 1

print(max(arr))
