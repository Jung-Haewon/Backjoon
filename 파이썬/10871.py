n, x = map(int, input().split())
number = map(int, input().split())

for i in number:
    if i < x:
        print(i, end = " ")
