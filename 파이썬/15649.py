n, m = map(int, input().split())
nums = list(range(1, n+1))
arr = ['']
ans = []

while nums:
    curNum = str(nums.pop(0))

    newArr = []
    for s in arr:
        newArr.append(s)
        newArr.append(s + curNum)
        
    arr = newArr

for s in arr:
    if len(s) == m:
        ans.append(s)

ans.sort()

for s in ans:
    print(*list(s))
