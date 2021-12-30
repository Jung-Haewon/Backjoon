tYear, tMon, tDay = map(int, input().split())
dYear, dMon, dDay = map(int, input().split())

day = [365 for x in range(10000)]
month = [0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

today = 0
targetDay = 0

for x in range(10000):
    if x % 4 == 0:
        day[x] = 366
        if x % 100 == 0:
            day[x] = 365
            if x % 400 == 0:
                day[x] = 366

if day[tYear] == 365:
    month[2] = 28
else:
    month[2] = 29
today = sum(day[1:tYear]) + sum(month[1:tMon]) + tDay

if day[dYear] == 365:
    month[2] = 28
else:
    month[2] = 29
    
targetDay = sum(day[1:dYear]) + sum(month[1:dMon]) + dDay
answer = targetDay - today

if answer >= 365243:
    print('gg')
else:
    print("D-" + str(answer))
