a = input();
trigger = False
n = len(a)

for i in range(n//2):
    if a[i] != a[n-1-i]:
        trigger = True
        break

if trigger == True:
    print(0)
else:
    print(1)
