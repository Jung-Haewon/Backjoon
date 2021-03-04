full_sentence = input('Enter a sentence: ')
first_word = full_sentence.find(' ')
last_word = full_sentence.rfind(' ')
print('First word: ', full_sentence[:first_word])
print('Last word: ', full_sentence[last_word+1:])

