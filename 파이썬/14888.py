def backTrack(p, m, x, d, number, result):
    global n, a, plus, minus, mux, div, first, best, worst
    
    if number == n - 1:
        if first == False:
            first = True
            best = result
            worst = result
        else:
            if result > best:
                best = result
            elif result < worst:
                worst = result
        return 0


    if p < plus:
        backTrack(p + 1, m, x, d, number + 1, result + a[number + 1])
    if m < minus:
        backTrack(p, m + 1, x, d, number + 1, result - a[number + 1])
    if x < mux:
        backTrack(p, m, x + 1, d, number + 1, result * a[number + 1])
    if d < div:
        backTrack(p, m, x, d + 1, number + 1, int(result / a[number + 1]))
        
n = int(input())
a = list(map(int, input().split()))
plus, minus, mux, div = list(map(int, input().split()))

first = False
worst = 0
best  = 0

backTrack(0, 0, 0, 0, 0, a[0])

print(best)
print(worst)
