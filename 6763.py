limit = int(input())
speed = int(input())
tmp = speed - limit

if tmp <= 0:
    print('Congratulations, you are within the speed limit!')
elif tmp <= 20:
    print('You are speeding and your fine is $100.')
elif tmp <= 30:
    print('You are speeding and your fine is $270.')
else:
    print('You are speeding and your fine is $500.')
