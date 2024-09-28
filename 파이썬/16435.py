n, l = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

for fruit in arr:
    if fruit <= l:
        l += 1
    else:
        break

print(l)
