
class Solution:
    def removeKdigits(self, num , k) :
        ans = []
        for i in num:
            while len(ans) > 0 and ans[-1] > i and k > 0:
                ans.pop()
                k = k - 1
            if len(ans) > 0 or i != '0':
               ans.append(i)
        if k > 0:
            ans = ans[:-k]

        if len(ans) > 0:
            return ''.join(ans)
        else:
            return '0'



if __name__ == '__main__':
    s = Solution()
    num = "10"
    k = 2
    num = "10200"
    k = 2
    num = "1234567890"
    k = 9
    ans = s.removeKdigits(num, k)
    print(ans)