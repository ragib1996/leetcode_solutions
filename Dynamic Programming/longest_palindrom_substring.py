
class Solution:
    def longestPalindrome(self, str):
        maxlen = 0
        ans = ""
        if len(str) <= 1:
            return str
        for i in range(0 , len(str)):

            for j in range( i + maxlen , len(str)):

                flag =  True
                test_case = str[i: j+1]
                left = 0
                right = len(test_case) - 1
                while left < right:
                    if test_case[left] != test_case[right]:
                        flag = False
                        break
                    left = left + 1
                    right = right - 1
                if flag == True and len(test_case) > maxlen:
                    ans =test_case
                    maxlen = len(test_case)


        return ans

if __name__ == '__main__':

    str = "forgeeksskeegfor"
    #str = "bc"
    s = Solution()
    ans = s.longestPalindrome(str)
    print(ans)
