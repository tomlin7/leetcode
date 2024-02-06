class Solution:
    def sequentialDigits(self, low: int, high: int):
        t = []
        
        for i in range(1,10):
            n=i
            nx=i+1
            while n<high and nx<=9:
                n=n*10+nx
                if low<=n<=high:
                    t.append(n)
                nx+=1
        
        return t

aa = Solution()
print(aa.sequentialDigits(100, 300))