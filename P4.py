def main():
    startingWord = input('Starting word: ')
    crossedOutLetters = ''
    remainingWord = ''

    for i in range(len(startingWord)):
        crossedOutLetters += startingWord[2*i : 2*i + 1 ] + ' '
        remainingWord += startingWord[2*i + 1 : 2*i + 2] + ' '

    print('Crossed out letters:', crossedOutLetters)
    print('Remaining letters:', remainingWord)

main()
