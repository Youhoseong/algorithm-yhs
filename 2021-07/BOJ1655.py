from heapq import heappush, heappop
import sys


N = int(sys.stdin.readline())

maxheap = []
minheap = []
for i in range(N):
    temp = int(sys.stdin.readline())

    if len(maxheap) == len(minheap):
        heappush(maxheap, -temp)
    else:
        heappush(minheap, temp)

    if minheap and -maxheap[0] > minheap[0]:
        max = -heappop(maxheap)
        min = heappop(minheap)

        heappush(maxheap, -min)
        heappush(minheap, max)

    print(-maxheap[0])
