class Solution(object):
    adj = []

    def addedge(self, numCourses):
        self.adj = [[] for i in range(numCourses)]

    def sort(self, i,  visited, s):

        visited[i] = True

        for j in self.adj[i]:
            if visited[j] == False:
                self.sort(j,  visited, s)

        s.append(i)

    def f(self, numCourses):
        #print(self.adj)
        position = {}
        s = []
        visited = [False] * numCourses
        for i in range(0, numCourses):

            if visited[i] == False:
                self.sort(i,  visited, s)

        topological_sort = []
        while len(s) > 0:
            topological_sort.append(s[-1])
            position[s[-1]] = len(topological_sort)
            s.pop()

        #print(topological_sort)

        for i in range(0, len(self.adj)):
            for j in self.adj[i]:
                first = position[i]
                second = position[j]
                if first >= second:
                    return False

        return True


    def canFinish(self, numCourses, prerequisites):
        self.addedge(numCourses)

        for i in prerequisites:
            self.adj[i[1]].append(i[0])

        return  self.f(numCourses)


if __name__ == "__main__":
    numCourses = 2
    prerequisites = [[1, 0]]
    #prerequisites = [[1, 0], [0, 1]]
    s = Solution()
    ans = s.canFinish(numCourses, prerequisites)
    print(ans)

