class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        seen = {}

        for n in nums:
            if n not in seen:
                seen[n] = 0
            seen[n] += 1
            if seen[n] > (len(nums)//2):
                return n
        return -1