
N, M = input().split()
N = int(N)
M = int(M)

tmep = []
for i in range(N):
    temp = input()
    tmep.append(temp)

print(tmep)

tt = []
for i in range(M):
    temp = input()
    if temp in tmep:
        tt.append(temp)


print(len(tt))
for i in tt:
    print(i)
