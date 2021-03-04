for i in range(3):
    h1, m1, s1, h2, m2, s2 = map(int, input().split())
    tmp = (h2*3600 + m2*60 + s2) - (h1*3600 + m1*60 + s1)
    print((tmp//3600)%24, (tmp//60)%60, tmp%60)
