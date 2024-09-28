n = int(input())
arr = set(input().split())
m = int(input())
quest = list(input().split())


for q in quest:
    if q in arr:
        print('1', end = ' ')
    else:
        print('0', end = ' ')
