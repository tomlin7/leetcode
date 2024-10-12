from collections import Counter

class Solution:
    def firstUniqChar(self, s: str) -> int:
        oc = Counter(s)
    
        for i,c in enumerate(s):
            if oc[c] == 1:
                return i

t = Solution()

print(t.firstUniqChar("loveleetcode"))
