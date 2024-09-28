def main():
    nums = scanData()
    ans = solveProblem(nums)
    printAnswer(ans)

def scanData():
    nums = []

    for _ in range(9):
        nums.append(int(input()))
    
    return nums

def solveProblem(nums):
    total = sum(nums)
    liar = []
    ans = []

    #가짜 난쟁이를 찾아내는 과정
    for i in range(9):
        for j in range(i + 1, 9):
            if (total - nums[i] - nums[j]) == 100:
                liar.append(i)
                liar.append(j)

    #진짜 난쟁이들로만 이루어진 리스트 생성
    for i in range(9):
        if i not in liar:
            ans.append(nums[i])

    return ans
    
def printAnswer(ans):
    for i in range(7):
        print(ans[i])

main()
