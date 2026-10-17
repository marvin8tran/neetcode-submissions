class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        res = nums[0]

        tmpsum = 0

        for val in nums:
            tmpsum += val
            res = max(res, tmpsum)
            if tmpsum < 0:
                tmpsum = 0
            
        return res

        