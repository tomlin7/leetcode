from typing import List


class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        l = []
        for i, n in enumerate(nums):
            d = [n]
            for j in nums[i+1:]:
                for k in d:
                    if not (k%j and j%k):
                        d.append(j)
            l = max(d, l, key=lambda x:len(x))
        
        return l
    

s = Solution()
print(s.largestDivisibleSubset([1,2,3]))