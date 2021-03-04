def main():
    number_people = int(input('How many people? '))

    first = []
    last = []
    current = []
    next_year = []


    for i in range(number_people):
        first.append(input('Enter first name: '))
        last.append(input('Enter last name: '))
        current.append(float(input('Enter current salary: ')))
        if current[i] < 40000:
            new = current[i] * 1.05
            next_year.append(new)
        else:
            new = current[i] + (current[i] - 40000) * 1.02 + 2000
            next_year.append(new)
        
    print('\n+'+"-"*9+"+"+"-"*14+"+"+"-"*14+"+"+"-"*19+"+"+"-"*19+'+')
    print("{0:<10}{1:<15}{2:<15}{3:<20}{4:<20}{5:<10}"
          .format('l '+"case.no", 'l '+"First Name", 'l '+"Last Name", 'l '+"Current Salary", 'l '+"New Salary", 'l'))
    print('+'+"-"*9+"+"+"-"*14+"+"+"-"*14+"+"+"-"*19+"+"+"-"*19+'+')
    
    for i in range(number_people):
        print("{0:<10}{1:<15}{2:<15}l ${3:<17,.2f}l ${4:<17,.2f}{5:<10}"
              .format('l '+"case "+str(i+1), 'l '+first[i], 'l '+last[i], current[i], next_year[i], 'l'))
    print('+'+"-"*9+"+"+"-"*14+"+"+"-"*14+"+"+"-"*19+"+"+"-"*19+'+')

main()        
