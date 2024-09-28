n = int(input())
s = list(input())

for i in range(1, n-1):
    if s[i] == 'F':
        if s[i-1] == 'F' or s[i+1] == 'F':
            continue
        
        if s[i-1] != s[i+1]:
            s[i] = 'B'

print(s)
