from collections import defaultdict
from typing import List
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if not strs:
            return []

        ss = defaultdict(list)
        for i in strs:
            s = ''.join(sorted(i))
            ss[s].append(i)
            
        return ss.values()
    
th = Solution()
print(th.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))