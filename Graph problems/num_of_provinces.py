# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
from collections import  deque

 # Press Ctrl+F8 to toggle the breakpoint.

def findCircleNum( isConnected) -> int:
    graph = {}

    for i in range(0, len(isConnected)):
        if i not in graph:
            graph[i] = []
        for j in range(0, len(isConnected)):
            if j == i:
                continue
            if j not in graph:
                graph[j] = []
            if isConnected[i][j] == 1:
                if j not in graph[i]:
                    graph[i].append(j)
                if i not in graph[j]:
                    graph[j].append(i)

    province = 0
    q = deque()
    visited = []
    for i in graph:
        if i in visited:
            continue
        q.append(i)
        while len(q) != 0:
            j = q[0]
            k = graph[j]

            for l in range(0, len(k)):
                if k[l] not in visited:
                    q.append(k[l])

            visited.append(q[0])
            q.popleft()

        province += 1

    return province


if __name__ == '__main__':


    isConnected = [[1,0,0],[0,1,0],[0,0,1]]

    ans = findCircleNum(isConnected)
    print(ans)
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
