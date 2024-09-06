
class Solution:
    def largestRectangleArea(self, heights):
        maxarea = 0
        a = []

        for i,h in enumerate(heights):
            start = i
            while len(a) > 0 and a[-1][1] > h:
                index, height = a.pop()
                maxarea = max (maxarea, height * (i-index))
                start = index
            a.append((start, h ))

        for i, h in a:
            maxarea = max(maxarea, h * (len(heights) - i))

        return maxarea


if __name__ == '__main__':
    s = Solution()
    heights = [7, 2, 7,7, 6, 4, 4]
    print(s.largestRectangleArea(heights))