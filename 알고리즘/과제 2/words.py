def read_data():
    f = open("words.inp", "r")
    ret = list(map(lambda x: x.rstrip(), f.readlines()[1:]))
    f.close()
    return ret

def print_data(data):
    f = open("words.out", "w")
    f.write(data)
    f.close()

def process(ret):
    
    b = set(ret)
    ans = 'NONE'

    if len(b) > len(ret)/2:
        return ans
        
    for i in b:
        if ret.count(i) > len(ret)/2:
            ans = i
            break
        
    return ans


ret = read_data()
ans = process(ret)
print_data(ans)










