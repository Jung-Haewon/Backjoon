a = []
exec('a.append(int(input()));'*4)
b = []
exec('b.append(int(input()));'*2)
a.remove(min(a))
print(sum(a)+max(b))
