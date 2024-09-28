input()
a = set(input().split())
b = set(input().split())
print(len(a-b)+len(b-a))
