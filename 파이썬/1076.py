res = {'black': 0, 'brown': 1, 'red': 2, 'orange': 3,
       'yellow': 4, 'green': 5, 'blue': 6, 'violet': 7,
       'grey': 8, 'white': 9}

a = res[input()]
b = res[input()]
c = res[input()]

ans = (10*a + b) * (10**c)
print(ans)
