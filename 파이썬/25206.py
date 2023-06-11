totalGradePoint = 0
totalCredit = 0

for _ in range(20):
    name, creditStr, grade = input().split()
    credit = float(creditStr)

    if grade == 'P':
        ''
        #do nothing
    elif grade == 'A+':
        totalCredit += credit
        totalGradePoint += credit * 4.5
    elif grade == 'A0':
        totalCredit += credit
        totalGradePoint += credit * 4.0
    elif grade == 'B+':
        totalCredit += credit
        totalGradePoint += credit * 3.5
    elif grade == 'B0':
        totalCredit += credit
        totalGradePoint += credit * 3.0
    elif grade == 'C+':
        totalCredit += credit
        totalGradePoint += credit * 2.5
    elif grade == 'C0':
        totalCredit += credit
        totalGradePoint += credit * 2.0
    elif grade == 'D+':
        totalCredit += credit
        totalGradePoint += credit * 1.5
    elif grade == 'D0':
        totalCredit += credit
        totalGradePoint += credit * 1.0
    elif grade == 'F':
        totalCredit += credit
        totalGradePoint += credit * 0

GPA = totalGradePoint / totalCredit
print(f"{GPA:.7}")
        
