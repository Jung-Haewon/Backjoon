n = int(input())
arr = []
total1 = 0.0
total2 = 0.0

for _ in range(n):
    x, y = map(int, input().split())
    arr.append([x, y])


for i in range(n-1):
    total1 += arr[i][0] * arr[i+1][1]
    total2 += arr[i+1][0] * arr[i][1]
    
total1 += arr[n-1][0] * arr[0][1]
total2 += arr[0][0] * arr[n-1][1]

total = abs((total1 - total2) / 2)
print(total)
