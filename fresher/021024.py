class Solution:
    def countSubstrings(self, s: str) -> int:
        n = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                ss = s[i:j]
                print(ss)
                n += int(ss == ss[::-1])
        
        return n


t = Solution()
print(t.countSubstrings("abc"))