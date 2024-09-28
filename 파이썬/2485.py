def gcd(a, b):
    r = a % b
    
    if r == 0:
        return b
    else:
        return gcd(b, r)

n = int(input())
tree = []
distance = []

for _ in range(n):
    tree.append(int(input()))

for i in range(n-1):
    distance.append(tree[i+1] - tree[i])

minGcd = distance[0]
for i in range(n-1):
    minGcd = gcd(minGcd, distance[i])

addTree = [i/minGcd - 1 for i in distance]
print(int(sum(addTree)))
