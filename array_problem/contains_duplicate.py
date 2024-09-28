

class Solution:
    def containsDuplicate(self, nums) :
        dict = {}

        for i in nums:
            if i not in dict:
                dict[i] = 1
            else:
                return True

        return False    


if __name__=="__main__":
    prices = [7,1,5,3,6,4]
    nums = [1,2,3,1]
    nums = [1,2,3,4]

    s = Solution()
    ans = s.containsDuplicate(nums)
    print(ans)