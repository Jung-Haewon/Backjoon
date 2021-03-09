a, b, c = map(int, input().split())

ans1 = (c//(a*7+b))*7
ans2 = ((c%(a*7+b))+a-1)//a

if ans2 > 7:
    ans2 = 7
    
print(ans1 + ans2)
