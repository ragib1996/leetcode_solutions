
class Solution:
    def carFleet(self, target , position, speed):
        dict = {}
        for i in range(0, len(position)):
            dict[position[i]] = speed[i]

        position.sort(reverse= True)
        stack = []

        for i in position:
            if len(stack) <= 0 or (target - i) / dict[i]  > stack[-1]:
                stack.append((target - i) / dict[i] )

        return len(stack)



if __name__ == '__main__':

    target = 10
    position = [4, 1, 0, 7]
    speed = [2, 2, 1, 1]

    target = 10
    position = [1, 4]
    speed = [3, 2]

    target = 10
    position = [3]
    speed = [3]

    target = 100
    position = [0, 2, 4]
    speed = [4, 2, 1]
    s = Solution()
    ans = s.carFleet(target, position, speed)
    print(ans)