for _ in range(int(input())):
    s = input()
    n = len(s) - 3
    
    if 'MOO' in s:
        n = n
    elif 'OOO' in s or 'MOM' in s:
        n += 1
    elif 'OOM' in s:
        n += 2
    else:
        n = -1

    print(n)
