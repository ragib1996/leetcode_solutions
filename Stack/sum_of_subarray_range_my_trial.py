
import math

class Solution:
    def subArrayRanges(self, nums):
        ans = 0

        for i in range(0, len(nums)):
            large = nums[i]
            small = nums[i]
            for j in range(i+1, len(nums)):
                large = max(large, nums[j])
                small = min(small, nums[j])
                ans  = ans + (large- small)

        return ans

if __name__ == '__main__':
    nums = [4, -2, -3, 4, 1]
    s = Solution()
    ans = s.subArrayRanges(nums)
    print(ans)