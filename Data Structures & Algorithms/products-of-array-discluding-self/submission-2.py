class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1] * len(nums)

        prefix = 1
        for i in range(len(nums)):
            res[i] *= prefix
            prefix *= nums[i]
        
        rightFix = 1
        for j in range(len(nums)-1, -1, -1):
            res[j] *= rightFix
            rightFix *= nums[j]

        return res
        