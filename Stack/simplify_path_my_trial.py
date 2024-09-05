
class Solution:
    def simplifyPath(self, path: str) -> str:
        t = path.split('/')
        ans = []
        for i in t:
            if i == '.' or i == '':
                continue
            elif i == '..':
                if len(ans) > 0:
                   ans.pop()
            else:
                ans.append(i)

        return  '/'+'/'.join(ans)


if __name__ == "__main__":
    path = "/home/../google.com/./facebook"
    path = "/home/"
    path = "/home//foo/"
    path = "/home/user/Documents/../Pictures"
    path = "/../"
    path = "/.../a/../b/c/../d/./"
    s = Solution()
    print(s.simplifyPath(path))