t=int(input())
for i in range(t):
    w=input()    
    for x in map(chr,range(97,123)):
        if x in w:
            a=w.find(x)
            b=len(w)-w[::-1].find(x)            
            if w[a:b]!=x*(b-a):
                t-=1
                break
print(t)
    
        
