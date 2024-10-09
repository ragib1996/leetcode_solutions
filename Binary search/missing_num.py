class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        
        nums.sort()
        s = nums[0]
        if s != 0:
            return 0
            
        for i in range(0, len(nums)):
            if i != 0:
                if nums[i] != nums[i-1] + 1:
                    return nums[i-1] + 1
                
        return nums[-1] + 1    
                    
                    
nums = [3,0,1]
nums = [9,6,4,2,3,5,7,0,1]
nums = [0,1]
s = Solution()
ans = s.missingNumber(nums)
print(ans )