class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        """
        max_value = 1
        min_value = 1
        ans = max_value

        for i in range(0, len(nums)):
            if i == 0:
                max_value = nums[i]
                min_value = nums[i]
                ans = max_value
            else:
                temp = max_value * nums[i]
                max_value = max(nums[i], temp , min_value * nums[i])
                min_value = min(nums[i], temp , min_value * nums[i] )
                ans = max(max_value, ans)

        return ans 
        """
        max_val = nums[0]
        min_val = nums[0]
        ans = nums[0]

        for i in range(1, len(nums)):
            t1 = max_val * nums[i]
            t2 = min_val * nums[i]
            max_val = max(nums[i], t1, t2)
            min_val = min(nums[i], t1, t2)
            ans = max(ans, max_val)

        return ans 


if __name__=="__main__":
    nums = [1,2,-3,4]
    nums = [-2,-1]
    nums=[-4,-3,-2]
    s = Solution()
    ans = s.maxProduct(nums)
    print(ans)
