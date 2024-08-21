class Solution:
    def rob(self, nums):
       rob1, rob2 = 0, 0

       for i in nums:
           temp = max(rob1 + i , rob2)
           rob1 = rob2
           rob2 = temp

       return  rob2




if __name__ == '__main__':
    nums = [2, 9, 8, 3, 6]
    nums = [1,1,3,3]
    nums = [2,1,1,2]
    s = Solution()
    ans = s.rob(nums)
    print(ans)
