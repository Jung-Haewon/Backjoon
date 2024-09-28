def main():
    x = scanData()
    ans = solveProblem(x)
    printAnswer(ans)

def scanData():
    x = int(input())
    return x

def solveProblem(x):
    sticks = [64, 32, 16, 8, 4, 2, 1]
    total = 0
    cnt = 0

    for stick in sticks:
        if total + stick <= x:
            total += stick
            cnt += 1

            if total == x:
                break

    return cnt

def printAnswer(ans):
    print(ans)

main()
