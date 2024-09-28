def backTrack(arr, level):
    global ans, m, stalls, conds
    
    if level == m:
        state = [0 for _ in range(101)]
        price = 0
        #print(arr)

        for i in range(m):
            if arr[i] == 1:
                price += conds[i][3]
                for j in range(conds[i][0], conds[i][1] + 1):
                    state[j] += conds[i][2]

        #print(state[0:10])

        for j in range(0, 101):
            if state[j] < stalls[j]:
                return
            
        if price < ans:
            ans = price

        return

    backTrack(arr[:], level+1)
    arr[level] = 1
    backTrack(arr[:], level+1)
    

def main():
    global ans, m, stalls, conds
    ans = 0
    n, m = map(int, input().split())
    stalls = [0 for _ in range(101)]
    conds = []

    for _ in range(n):
        s, t, c = map(int, input().split())

        for i in range(s, t + 1):
            if stalls[i] < c:
                stalls[i] = c

    for _ in range(m):
        a, b, p, c = map(int, input().split())
        conds.append([a, b, p, c])
        ans += c

    backTrack([0 for _ in range(m)], 0)

    print(ans)

main()
