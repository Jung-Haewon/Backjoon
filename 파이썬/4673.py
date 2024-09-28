def d(a):
    ret = int(a)
    for c in a:
        ret += int(c)
    return ret



ans = list(range(1, 10000))

for i in range(1, 10000):
    tmp = d(str(i))
    
    if tmp in ans:
        ans.remove(tmp)
        
print(*ans, sep = '\n')
