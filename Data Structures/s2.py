n,q = list(map(int,input().split()))
l = list(map(int,input().split()))
suml = []
finalf = 0
for i in range(n):
    finalf ^= l[i]
l.append(finalf)
s = 0

for i in range(n):
    s ^= l[i]
    suml.append(s)
suml.append(s^finalf)
print(l,suml)
for _ in range(q):
    uni = n+1
    newq = int(input())
    if newq < uni:
        sum1 = 0
        for j in range(newq):
            sum1 ^= l[j]
        print(sum1)
        continue
    rem = newq%uni;
    final = suml[-1]
    for j in range(rem):
        final ^= l[j]
    print(final)

