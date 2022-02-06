n = int(input())
arr = list(map(int, input().split()))

tmp = set(arr)
sortArr = list(tmp)
sortArr.sort()

a = {}
for i in range(len(sortArr)):
    a[sortArr[i]] = i

answer = ""

for i in range(n):
    answer += str(a[arr[i]]) + " "
    
print(answer)
