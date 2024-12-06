from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        res = defaultdict(list)
        for s in strs:
            t = ''.join(sorted(s))
            res[t].append(s)

        return list(res.values())
    
strs = ["eat","tea","tan","ate","nat","bat"]
s = Solution()
ans = s.groupAnagrams(strs)

print(ans)