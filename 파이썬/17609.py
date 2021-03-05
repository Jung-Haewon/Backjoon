for _ in range(int(input())):
    n = list(input())
    check = 0
    for i in range(len(n)//2):
        if n[i] != n[-1-i]:
            tmp1 = n[:]
            del(tmp1[i])
            if tmp1 != tmp1[::-1]:
                check += 1
                
            tmp2 = n[:]
            del(tmp2[-1-i])
            if tmp2 != tmp2[::-1]:
                check += 1
            break
    print(check)
