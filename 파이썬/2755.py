def floor(a, k):
    a = list(map(lambda x : sum(a[0:x]), range(1, len(a)+1)))
    k -= 1
    if k != 0:
        a = floor(a, k)
    return a

for i in range (int(input())):
    k, n = int(input()), int(input())
    tmp = list(range(1, n+1))

    tmp = floor(tmp, k)
    print(tmp[n-1])
