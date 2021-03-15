import math

for i in range(int(input())):
    a, b = map(int, input().split())

    tmp = 1
    ans = 0
    
    for i in range(7):
        tmp += i
        if a < tmp:
            ans = [0, 500, 300, 200, 50, 30, 10][i]
            break

         
    if b != 0 and b < 32:
        ans += [512, 256, 128, 64, 32][int(math.log(b, 2))]
    
    print(ans*10000)
