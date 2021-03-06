t, p = map(int, input().split())
if p < 20:
    print((p*2)*((100-p+(20-p))/t))
    
else:  
    print((p+20)*((100-p)/t))
