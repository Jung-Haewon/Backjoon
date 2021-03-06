n = list(map(int, input().split()))
if sum(n) >= 100:
    print('OK')
else:
    print(['Soongsil','Korea','Hanyang'][n.index(min(n))])
    
