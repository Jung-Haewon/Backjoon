def main():
    n = scanData()
    ans = solveProblem(n)
    printAnswer(ans)

def scanData():
    n = int(input())
    return n

def solveProblem(n):
    ans = 0
    
    for i in range(1, n + 1):
        ans += str(i).count('3') + str(i).count('6') + str(i).count('9')
        #print(i, ans)

    return ans

def printAnswer(ans):
    print(ans)

main()
