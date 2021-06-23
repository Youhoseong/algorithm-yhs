
N, M = input().split()
N = int(N)
M = int(M)

a = set()
for i in range(N):
    a.add(input())


b = set()
for i in range(M):
    b.add(input())

r = sorted(list(a & b))

print(len(r))
for i in r:
    print(i)
