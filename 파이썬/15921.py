if input() == '0':
    print('divide by zero')
else:
    n = sum(map(int, input().split()))
    if n == 0:
        print('divide by zero')
    else:
        print('1.00')
