e, s, m = map(int, input().split())

if e == 15:
    e = 0
    
if s == 28:
    s = 0
    
if m == 19:
    m = 0

cnt = 1

while True:
    if cnt % 15 == e and cnt % 28 == s and cnt % 19 == m:
        break
    cnt += 1

print(cnt)
