a = int(input())
x = int(input())
b = int(input())
y = int(input())
t = int(input())

ans1 = a + max(0, t-30)*x*21
ans2 = b + max(0, t-45)*y*21

print(ans1, ans2)
