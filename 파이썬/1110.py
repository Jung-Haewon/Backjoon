n = input()
if int(n) < 10:
    n = '0'+n
new = n
i = 0
while True:
    plus = int(new[0]) + int(new[1])
    new = new[1] + str((plus % 10))
    i += 1
    if new == n:
        break
print(i)
        
