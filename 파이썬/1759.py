l, c = map(int, input().split())
arr = sorted(input().split())

ans = []
stack = [['', 1], [arr[0], 1]]

while len(stack) > 0:
    top = stack.pop()
    s = top[0]
    idx = top[1]

    if len(s) == l:
        cnt = 0
        
        for i in ['a', 'e', 'i', 'o', 'u']:
            if i in s:
                cnt += 1

        if cnt > 0 and l - cnt > 1:
            ans.append(s)

    elif idx == c:
        continue
    else:
        stack.append([s, idx+1])
        stack.append([s + arr[idx], idx+1])

print(*ans, sep = '\n')
