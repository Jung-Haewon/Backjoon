n = int(input())


sunser = (n-1)%4+1
number = (n-1)//4


if number%2 == 1:
    sunser = 6 - sunser
                
print(sunser)
