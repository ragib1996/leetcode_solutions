class Solution:
    def maxProfit(self, prices):
        
        ans  = 0
        small = prices[0]

        for i in prices:
          if i < small:
              small = i 
          t = i - small 
          ans = max(ans, t)

        return ans

if __name__=="__main__":
    prices = [7,1,5,3,6,4]
    #prices = [7,6,4,3,1]

    s = Solution()
    ans = s.maxProfit(prices)

    print(ans)