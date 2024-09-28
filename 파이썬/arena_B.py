n = int(input())
strings = []

first = ''
end = ''
cnt = 0

for i in range(n):
    strings.append(input())

    if strings[i] == '?':
        cnt = i

if cnt != 0:
    first = strings[cnt-1][-1]

if cnt != n-1:
    end = strings[cnt+1][0]



for _ in range(int(input())):
    tmp = input()

    if tmp in strings:
        continue

    if cnt != 0:
        if tmp[0] != first:
            continue

    if cnt != n-1:
        if tmp[-1] != end:
            continue

    print(tmp)
    break
