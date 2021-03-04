c = int(input())
for i in range(c):
    a = list(map(int, input().split()))
    n = a[0]
    mean = (sum(a[1:]))/n
    number = 0
    for j in range(n):
        if a[j+1] > mean:
            number += 1
    print("{:.3f}%".format(number/n*100))
