for x in range(int(input())):
    h, w, n = map(int, input().split())
    t=''
    a = (n//h)+1
    b = n%h
    if b == 0:
        b = h
        a -= 1
    if a < 10:
        t='0'
    print(b, t, a, sep = '')
    
