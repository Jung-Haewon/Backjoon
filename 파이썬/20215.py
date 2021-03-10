w, h = map(int, input().split())

ans1 = w + h
ans2 = (w**2 + h**2)**.5
print(ans1 - ans2)
