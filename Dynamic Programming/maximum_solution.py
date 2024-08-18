# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


class Solution:
    def maxSubArray(self, nums ):

        total = 0
        ans = nums[0]

        for i in nums:
            total = total + i
            if total > ans:
                ans = total
            if total < 0:
                total = 0

        return ans

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    nums = [5, 4, -1, 7, 8]
    nums = [1]
    s = Solution()
    ans = s.maxSubArray(nums)
    print(ans)


# See PyCharm help at https://www.jetbrains.com/help/pycharm/
