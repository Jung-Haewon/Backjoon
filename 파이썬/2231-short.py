n=int(input())    
try:
    print([x for x in range(n)if x+sum(map(int,str(x)))==n][0])
except:
    print(0)
