w=input()
a=list(range(26))
b=list(map(lambda a : a%1, a))

for i in w:
    tmp = ord(i)
    if tmp > 96:
        tmp = tmp-32
    b[tmp-65] += 1

if b.count(max(b)) == 1:
    print(chr(b.index(max(b))+65))
else:
    print("?")
