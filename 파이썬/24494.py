correct = []
guess = []
equals = []

green = 0
yellow = 0

for i in range(3):
    correct += list(input())

for i in range(3):
    guess += list(input())

print(correct)
print(guess)

for i in range(9):
    if correct[i] == guess[i]:
        green += 1
        equals.append(correct[i])

for e in equals:
    correct.remove(e)
    guess.remove(e)

print(equals)
print(correct)
print(guess)

for c in correct:
    if c in guess:
        yellow += 1
        guess.remove(c)

print(green)
print(yellow)
