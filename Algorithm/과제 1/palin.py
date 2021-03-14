def read_data():
    f = open("palin.inp", "r")
    ret = f.readlines()[1:]
    f.close()
    return ret

def print_data(data):
    f = open("palin.out", "w")
    for data_segment in data:
        f.write(data_segment+"\n")
    f.close()

def process(ret):
    ans = []
    for x in ret:
        n = list(x.rstrip())
        check = 1
        for i in range(len(n)//2):
            if n[i] != n[-1-i]:
                check += 1
                
                tmp1 = n[:]
                del(tmp1[i])
                tmp2 = n[:]
                del(tmp2[-1-i])
                
                if tmp1 != tmp1[::-1] and tmp2 != tmp2[::-1]:
                    check += 1                
                break
        ans.append(str(check))
    return ans

print_data(process(read_data()))
