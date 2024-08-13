# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


class Solution:
    def canVisitAllRooms(self, rooms):

        visited = []
        visited.append(0)
        complete = []


        for i in visited:
            for j in rooms[i]:
                if j not in visited:
                    visited.append(j)

        if len(visited) == len(rooms):
            return True
        else:
            return False


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    rooms  = [[1],[2],[3],[]]
    s = Solution()
    ans = s.canVisitAllRooms(rooms)
    print(ans)

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
