def main():
    digit = int(input("How many digits is it? "))
    multiple = int(input("How many times multiply? "))
    
    special_before, special_after = 0, 0
    
    for i in range(10**(digit-1), 10**digit):
        number = []
        tmp = i
        abcd = ''
        dcba = ''
        
        for j in range(digit):
            number.append(tmp // (10**(digit-j-1)))
            tmp = tmp % (10**(digit-j-1))       

        for j in range(digit):
            abcd += str(number[j])
            dcba += str(number[digit-1-j])
            
        if int(abcd) * multiple == int(dcba):
            special_before = int(abcd)
            special_after = int(dcba)

    if special_before == 0:
        print('There is no special number.')
    else:
        print('Since 4 times', special_before, 'is', special_after)
        print('the special number is ', special_before, '.')
    
    
main()
