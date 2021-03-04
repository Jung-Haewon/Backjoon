a = []

for i in range(int(input())):
    b = input()
    if b not in a:
        a.append(b)
        
a.sort() 
a.sort(key = len)

for i in a:
    print(i)
