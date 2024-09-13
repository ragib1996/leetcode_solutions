# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


class Solution:
    def nextGreaterElements(self, nums):
        ans = [-1] * len(nums)
        for i in range(0, len(nums)):
            a1 = nums[i+1:]
            a2 = nums[:i]
            b = False

            for j in range(0, len(a1)):
                if a1[j] > nums[i]:
                    ans[i] = a1[j]
                    b = True
                    break
            if b == False:
                for j in range(0, len(a2)):
                    if a2[j] > nums[i]:
                        ans[i] = a2[j]
                        b = True
                        break

        return  ans


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    nums = [1, 2, 1]
    nums = [1, 2, 3, 4, 3]
    s = Solution()
    ans = s.nextGreaterElements(nums)
    print(ans)

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
