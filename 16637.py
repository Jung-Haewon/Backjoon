from itertools import combinations

def main():
    num = int(input())//2
    #text = input()
    ans = case(num)
    print(ans)

def case(num):
    ans = []
    big = (num+1)//2

    for i in range(num):
        ans.append([i])

    
    for i in range(2, big+1):
        tmp = list(map(list, combinations(list(range(num)), i)))
        for j in range(len(tmp)):
            for k in range(1,i):
                if tmp[j
            
    return ans

main()
