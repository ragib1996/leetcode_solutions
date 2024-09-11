

class Solution:
    def dailyTemperatures(self, temperatures):
        stack = []
        ans = [0 ] * len(temperatures)

        for i, t in enumerate(temperatures):
            while len(stack) > 0 and stack[-1][0] < t:
                t2, i2 = stack.pop()
                ans[i2] = i - i2
            stack.append([t,i])

        return  ans




if __name__ == '__main__':
    temperatures = [30, 38, 30, 36, 35, 40, 28]
    temperatures = [22, 21, 20]
    s = Solution()
    print(s.dailyTemperatures(temperatures))