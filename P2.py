full_sentence = input('Enter a 3-part name: ')
first_word = full_sentence.find(' ')
last_word = full_sentence.rfind(' ')
print('Middle name: ', full_sentence[first_word+1:last_word])
