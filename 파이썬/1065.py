ans = 0
for i in range(1, int(input())+1):
    if i < 100:
        ans += 1
    else:
        one = i%10
        ten = i%100//10
        hund = i//100
        if hund-ten==ten-one:
            ans+=1
print(ans)
