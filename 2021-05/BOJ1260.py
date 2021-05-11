
from collections import defaultdict

vertex, edge, startVertex = input().split()
vertex = int(vertex)
edge = int(edge)
startVertex = int(startVertex)
graph = defaultdict(list)

queue = []

def dfs(start):
    visit = []
    stack = []

    stack.append(start)
    while stack:
        now = stack.pop()
        if now not in visit:
            print(now, end=' ')
            visit.append(now)
            stack.extend(reversed(graph[now]))


def bfs(start):
    visit = []
    queue = []

    queue.insert(0, start)

    while queue:
        now = queue.pop(0)

        if now not in visit:
            print(now, end= ' ')
            visit.append(now)
            queue.extend(graph[now])


for i in range(0, edge):
    start, end = input().split()
    start = int(start)
    end = int(end)
    graph[start].append(end)
    graph[end].append(start)


for key in graph.keys():
    graph[key].sort()



dfs(startVertex)
print()
bfs(startVertex)
