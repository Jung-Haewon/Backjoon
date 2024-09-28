import sys

s = sys.stdin.readline().rstrip()
sub = []

cnt = 0
guard = False
for i in range(len(s)):
    if s[i] == ' ':
        if guard == False:
            sub.append((s[cnt: i])[::-1] + ' ')
            cnt = i+1
        continue
    
    if s[i] == '<':
        if cnt != i:
            sub.append((s[cnt: i])[::-1])
        guard = True
        cnt = i

    if s[i] == '>':
        guard = False
        sub.append(s[cnt: i+1])
        cnt = i+1
        continue

    if i == len(s)-1:
        sub.append((s[cnt: i+1])[::-1])

ans = "".join(sub)
sys.stdout.write(ans)
