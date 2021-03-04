a = 300
b = 60
c = 10

t1 = int(input())
t2 = t1%a
t3 = t2%b

if t1%10 != 0:
    print(-1)
else:
    print(t1//a, t2//b, t3//c)
