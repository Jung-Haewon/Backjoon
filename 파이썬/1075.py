n = int(input())
f = int(input())

n = (n//100)*100
tmp = n % f

if tmp != 0 :
    ans = str(n + (f-tmp))
else :
    ans = str(n)
    
print(ans[-2:])
