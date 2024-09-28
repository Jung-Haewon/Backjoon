def main():
    p, k = scanData()
    ans = solveProblem(p, k)
    printAnswer(ans)

def scanData():
    p, k = map(int, input().split())
    return p, k

def solveProblem(p, k):
    if p**0.5 >= k:
        return "GOOD"
    else:
        return "BAD"
    
def printAnswer(ans):
    print(ans)

main()
