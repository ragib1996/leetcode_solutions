# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

class Solution:
    def convert(self, s: str, numRows: int) :
        b = True
        t = [''] * numRows
        i = 0

        while i < len(s):
            for j in range(i, i+numRows):
                if j >= len(s):
                    break
                t[j - i] += s[j]

            i = j + 1
            temp = numRows - 2
            while i < len(s) and temp > 0:

                t[ temp ] += s[i]
                i += 1
                temp -= 1

        ans = ''
        for i in t:
            ans += i

        return ans

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    s = "PAYPALISHIRING"
    numRows = 3
    s = "ABC"
    numRows = 1
    S = Solution()
    ans = S.convert(s, numRows)
    print(ans)


# See PyCharm help at https://www.jetbrains.com/help/pycharm/
