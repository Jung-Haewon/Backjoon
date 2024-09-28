poly = input()
ans = ""

cnt = 0
for c in poly:
    if c == 'X':
        if cnt == 3:
            cnt = 0
            ans += "AAAA"
        else:
            cnt += 1
    else:
        if cnt == 0:
            ans += "."
        elif cnt % 2 == 1:
            ans = "-1"
            break
        else:
            ans += "BB."
            cnt = 0

if cnt == 2:
    ans += "BB"
elif cnt % 2 == 1:
    ans = "-1"
elif ans == "":
    ans = "-1"
    
print(ans)
