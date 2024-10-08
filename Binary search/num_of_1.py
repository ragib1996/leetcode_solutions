class Solution:
    def hammingWeight(self, n: int) -> int:
        ans  = 0
        while n != 0:
            if n % 2 == 1:
                ans += 1
            n = n // 2

        return ans  

if __name__ == '__main__':
    n = 11
    n = 128
    s = Solution()
    ans = s.hammingWeight(n)
    print(ans)