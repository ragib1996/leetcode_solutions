

class Solution:

    def allPathsSourceTarget(self, graph):
        paths = []
        stack = [(0,[0])]

        while len(stack) != 0:
            node, path = stack.pop()

            if node == len(graph)-1:
                paths.append(path)

            for child in graph[node]:
                stack.append((child, path + [child]))
        return paths




if __name__ == '__main__':
    graph = [[1, 2], [3], [3], []]
    s = Solution()
    ans = s.allPathsSourceTarget(graph)
    print(ans)