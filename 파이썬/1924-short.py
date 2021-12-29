m=[0,31,28,31,30,31,30,31,31,30,31,30,31]
w=['SUN','MON','TUE','WED','THU','FRI','SAT']
x,y=map(int,input().split())
print(w[(sum(m[0:x])+y)%7])
