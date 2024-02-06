from collections import Counter, defaultdict


class Solution:
    def min_window(self, s: str, t: str) -> str:
        occ=Counter(t)
        rn,rq=0,len(occ)
        final=float('inf'),0,0
        window=defaultdict(int)
        
        l,r=0,0
        while r<len(s):
            c=s[r]
            window[c] += 1
            if c in occ and window[c] == occ[c]:
                rn += 1
    
            while l<=r and rn==rq:
                if final[0]>(r-l+1):
                    final=(r-l+1),l,r
                p=s[l]
                window[p] -= 1
                if p in occ and window[p]<occ[p]:
                    rn -= 1
                l += 1

                print(f"{s[:l]}\033[34m[{s[l:r+1]}]\033[0m{s[r+1:]}")
            
            r += 1

        return "" if final[0]==float('inf') else s[final[1]:final[2]+1]
        
a = Solution()
print(a.min_window("cabwefgewcwaefgcf", "cae"))