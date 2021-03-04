a = input()
w = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
tmp = 0
i = 0
while i < len(a):
    if a[i:i+3] == w[2]:
        i += 3
    elif a[i:i+2] in w:
        i += 2
    else:
        i += 1
    tmp += 1
print(tmp)
