class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        d,e=0,0
        for v in nums:
            if v>0:d+=1
            elif v<0:e+=1
        if d>e:return d
        else:return e