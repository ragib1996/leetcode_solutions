
class Solution:
    def generateParenthesis(self, n):
        stack = []
        ans = []

        def backtrack(open, close):
            if open == n and close == n:
                ans.append(''.join(stack))
                return

            if open < n:
                stack.append('(')
                backtrack(open+1, close)
                stack.pop()

            if close < open:
                stack.append(')')
                backtrack(open, close+1)
                stack.pop()

        backtrack(0,0)
        return ans

if __name__ == '__main__':
    s = Solution()
    n = int(input())
    ans = s.generateParenthesis(n)
    print(ans)


