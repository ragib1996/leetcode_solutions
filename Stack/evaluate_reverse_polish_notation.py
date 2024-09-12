

class Solution:
    def evalRPN(self, tokens):
        s = []

        for i in tokens:
            if i == '+':
                s.append( s.pop() + s.pop() )
            elif i == '*':
                s.append(s.pop() * s.pop())
            elif i == '-':
                a = s.pop()
                b = s.pop()
                s.append(b-a)
            elif i == '/':
                a = s.pop()
                b = s.pop()
                s.append( int (b/a))
            else:
                s.append(int(i))

        return  s[0]

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    tokens = ["1", "2", "+", "3", "*", "4", "-"]
    tokens = ["4", "13", "5", "/", "+"]
    s = Solution()
    print(s.evalRPN(tokens))