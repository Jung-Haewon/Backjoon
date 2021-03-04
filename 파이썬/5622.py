a = list(map(lambda x: ord(x)-64, input()))
b = [[1,2,3],[4,5,6],[7,8,9],[10,11,12],[13,14,15],[16,17,18,19],[20,21,22],[23,24,25,26]]
tmp = 0
for x in a: 
    for i in b:
        if x in i:
            tmp+=b.index(i)+3
print(tmp)
