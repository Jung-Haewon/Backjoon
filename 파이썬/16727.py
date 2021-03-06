p1, s1 = map(int, input().split())
s2, p2 = map(int, input().split())

if p1+p2 != s1+s2:
    print(['Persepolis','Esteghlal'][p1+p2<s1+s2])
else:
    if p2 != s1:
        print(['Persepolis','Esteghlal'][p2<s1])
    else:
        print('Penalty')
