def main():
    
    mission = input('alphabet: ')
    word = input('word: ')

    times = find_substring(word, mission)

    print('count :', times)


def find_substring(word, mission):
    times = 0
    for i in range(len(word)):
        if word[i] == mission:
            times += 1

    return times
        

main()
