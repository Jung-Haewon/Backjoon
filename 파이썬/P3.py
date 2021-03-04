def main():

    count = int(input('How many numbers do you want to enter? '))

    numbers = []

    for i in range(count) :
        numbers.insert(i, int(input('Enter a number: ')))

    numbers.sort()

    if count % 2 == 0:
        median1 = (count//2) - 1
        median2 = count//2
        median = (numbers[median1] + numbers[median2]) / 2
        
    else:
        median = numbers[count//2]

    print('Median: ', median)

main()
