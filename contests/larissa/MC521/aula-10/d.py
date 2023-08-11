VISITED = 1
UNVISITED = 2

dfs_num = [UNVISITED for i in range(105)]
adjList = [[] for i in range(105)]

def dfs(u):
    dfs_num[u] = VISITED
    for v in adjList[u]:
        if(dfs_num[v] == UNVISITED):
            dfs(v)

v = int(input())

while(v != 0) :
    adjList = [[] for i in range(105)]
    line = [int(i) for i in input().split(' ')]
    a = line[0]

    while a != 0:
        for b in line[1:]:
            adjList[a].append(b)
            adjList[b].append(a)

        line = [int(i) for i in input().split(' ')]
        a = line[0]

    numCrit = 0
    for i in range(1, v+1):
        dfs_num = [UNVISITED for i in range(105)]
        dfs_num[i] = VISITED
        if(i == 1):
            dfs(2)
        else:
            dfs(1)

        for j in range(1, v+1):
            if (dfs_num[j] == UNVISITED and j != i):
                numCrit +=1
                break
    print(numCrit)
    
    v = int(input())