class Solution:
    def canJump(self, nums: List[int]) -> bool:

        reach = 0
        end = len(nums)

        for i, val in enumerate(nums):
            if i > reach:
                return False
            reach = max(reach, i + val)

        return True
        