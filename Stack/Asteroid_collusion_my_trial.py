class Solution:
    def asteroidCollision(self, asteroids):
        stack = []

        for a in asteroids:
            while len(stack) > 0 and a < 0 and stack[-1] > 0:
                d = stack[-1] + a
                if d > 0:
                    a = 0
                elif d < 0:
                    stack.pop()
                else:
                    stack.pop()
                    a = 0
            if a != 0:
                stack.append(a)

        return stack

if __name__ == '__main__':
    asteroids = [5,10,-10]
    s = Solution()
    print(s.asteroidCollision(asteroids))