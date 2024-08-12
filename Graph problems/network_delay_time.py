# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

from collections import deque
import sys
class Solution:
  def networkDelayTime(self, times, n, k):

    graph = []
    for i in range(0, n+1):
        graph.append([-1] * (n+1))

    for  i in times:
        graph[i[0]][i[1]] = i[2]

    completed = []
    visited = []
    visited.append(k)
    q = deque()
    q.append(k)
    ans = [sys.maxsize] * (n+1)
    ans[k] = 0
    temp_node = []
    high_val = 0

    while (True):
        for i in visited:
            if i in completed:
                continue
            for j in range(1, n+1):
                if j == i or j == k:
                    continue
                if graph[i][j] != -1 and ans[j] > ans[i] + graph[i][j]:
                    ans[j] = ans[i] + graph[i][j]
                    if j not in temp_node:
                       temp_node.append(j)

            completed.append(i)
        small_val = sys.maxsize
        small = sys.maxsize
        if len(temp_node) == 0:
            break
        for l in temp_node:
            if ans[l] < small_val:
                small = l
                small_val = ans[l]
        visited.append(small)
        if small_val > high_val:
            high_val = small_val
        temp_node.remove((small))


    if len(visited) == n:
        return high_val
    else:
        return  -1


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    times = [[3,5,78],[2,1,1],[1,3,0],[4,3,59],[5,3,85],[5,2,22],[2,4,23],[1,4,43],[4,5,75],[5,1,15],[1,5,91],[4,1,16],[3,2,98],[3,4,22],[5,4,31],[1,2,0],[2,5,4],[4,2,51],[3,1,36],[2,3,59]]
    n = 5
    k = 5
    s = Solution()

    ans  = s.networkDelayTime(times, n, k)
    print(ans)

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
