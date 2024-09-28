arr = [ 0 for _ in range(10)]

for _ in range(5):
    tmp = int(input())
    arr[tmp] += 1

for i in range(10):
    if arr[i] % 2 == 1:
        print(i)
        break
