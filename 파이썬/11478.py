s = input()
sub = set()

for i in range(len(s) + 1):
    for j in range(i + 1, len(s) + 1): 
        sub.add(s[i:j])

print(len(sub))
