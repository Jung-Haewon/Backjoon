n, m = map(int, input().split())
curArr = [ i for i in range(1, n+1)]
newArr = []

for _ in range(m):
    i, j = map(int, input().split())
    i -= 1
    j -= 1
    newArr = curArr.copy()

    x = i
    y = j

    for __ in range(i, j+1):
        newArr[x] = curArr[y]
        x += 1
        y -= 1

    curArr = newArr.copy()
        
print(*curArr)
