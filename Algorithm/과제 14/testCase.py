import random
 
num = 50000 #문자열 개수
max_len = 100 # 문자열 최대 길이
 
f = open('./read.inp', mode='wt', encoding='utf-8')
sf = open('./read_sort.inp', mode='wt', encoding='utf-8')
arr = []
 
for j in range(0, num):
    _strlen = random.randrange(4, max_len + 1)
    _1000strlen = 1000
    string_pool = "aaaaccgggt"
    result = ""
    for i in range(_strlen):
        result += random.choice(string_pool)
    #print("{} {}".format(j, result))
    arr.append(result + "\n")
    f.write(result + "\n")
 
arr = sorted(arr)

for i in range(1, 5):
    ans = (i * num) // 5
    sf.write(str(ans) + ": " + arr[ans])
    
for j in range(0, num):
    sf.write(str(j) + ": " + arr[j])
 
print("DONE")
f.close()
sf.close()
