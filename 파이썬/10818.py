n = int(input())
number = input().split()
for i in range(n):
    number[i] = int(number[i])
number.sort()
print("{} {}".format(number[0], number[n-1]))
