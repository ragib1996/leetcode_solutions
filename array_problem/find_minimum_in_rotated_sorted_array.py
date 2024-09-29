
class Solution:
    def findMin(self, nums):
        low = 0
        high = len(nums) - 1

        while low <= high:

            if nums[low] <= nums[high]:
                return nums[low]
            
            mid = (low+high) // 2

            if nums[mid] > nums[high]:
                low = mid + 1
            else:
                high = mid


if __name__=="__main__":
    nums = [3,4,5,1,2]
    nums = [1,2,3,4,5]
    nums = [4,5,6,7,0,1,2]
    nums = [11,13,15,17]
    nums = [1]


    s = Solution()
    print(s.findMin(nums))