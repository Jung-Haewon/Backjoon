n = int(input())
k = int(input())

print(min(k+60, n)*1500 + max(n-k-60, 0)*3000)
