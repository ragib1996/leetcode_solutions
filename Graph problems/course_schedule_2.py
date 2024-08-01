# This is a sample Python script.
import copy

class Solution:
    def findOrder(self, numCourses, prerequisites ):

        graph = {}
        pre_sub = {}

        for i,j  in prerequisites:
            if j not in graph:
                graph[j] = []
            graph[j].append(i)
            if i not in pre_sub:
                pre_sub[i] = []
            pre_sub[i].append(j)

        complete = []
        no_prerequisitie = []
        for i in range(0, numCourses):
            if i not in pre_sub:
                no_prerequisitie.append(i)
                complete.append(i)

        if len(no_prerequisitie) == 0:
            return  complete

        for i in range(0, len(no_prerequisitie)):
            stack = []
            if no_prerequisitie[i] in graph:
                stack = copy.deepcopy(graph[no_prerequisitie[i]])

            while len(stack) > 0:


                b = False
                for p in pre_sub[stack[len(stack) - 1 ]]:
                    if p not in complete:
                       b = True
                       break
                if b == False and stack[len(stack) - 1 ] not in complete:
                    complete.append(stack[len(stack) - 1 ])
                    t = stack.pop()
                    if t in graph:
                        stack = stack + graph[t]
                else:
                    stack.pop()

        if len(complete) == numCourses:
            return complete

        return  []



# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    numCourses = 4
    prerequisites =   [[1,0],[2,0],[3,1],[3,2]]
    s= Solution()
    ans = s.findOrder(numCourses, prerequisites)
    print(ans)

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
