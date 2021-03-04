import datetime
a , b = map(int, input().split())
tmp = datetime.datetime(2021, 2, 23, a, b) + datetime.timedelta(minutes=int(input()))
print(tmp.hour, tmp.minute)
