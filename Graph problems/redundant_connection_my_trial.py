from collections import deque

def findRedundantConnection(edges ):
    nodes = []
    graph = {}
    visited_node = []
    used_edge = []

    def isCycle(a,b, visited_node):
        q = deque()
        q.append(a)
        v = []
        while(len(q) != 0):
            l = graph[q[0]]

            for m in l:
                if m not in visited_node:
                    continue
                if q[0] == a and m == b:
                    continue
                if m == b :
                    if [ q[0], m] in used_edge or [m, q[0]] in used_edge:
                        return  True
                if m not in v and ( [ q[0], m] in used_edge or [m, q[0]] in used_edge):
                    q.append(m)
            v.append(q[0])
            q.popleft()
        return  False


    for i in edges:
        if i[0] == i[1]:
            continue
        if i[0] not in nodes:
            nodes.append(i[0])
        if i[1] not in nodes:
            nodes.append(i[1])
        if i[0] not in graph:
            graph[i[0]] = []
        if i[1] not in graph:
            graph[i[1]] = []
        if i[1] not in graph[i[0]]:
            graph[i[0]].append(i[1])
        if i[0] not in graph[i[1]]:
            graph[i[1]].append(i[0])

    for i in edges:
        if i[0] in visited_node and i[1] in visited_node:
            b = isCycle(i[0], i[1], visited_node)
            if b == True:
                return [i[0], i[1]]
        else:
            if i[0] not in visited_node:
                 visited_node.append(i[0])
            if i[1] not in visited_node:
                 visited_node.append(i[1])
        used_edge.append(i)

if __name__ == '__main__':

    edges = [[1,5],[3,4],[3,5],[4,5],[2,4]]
    ans = findRedundantConnection(edges)
    print(ans)