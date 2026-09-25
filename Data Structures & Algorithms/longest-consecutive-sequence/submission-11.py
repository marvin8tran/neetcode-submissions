class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        s = set(nums)
        res = 0

        for val in s:
            if val - 1 not in s:
                tmp = val
                x = 0
                while tmp in s:
                    x += 1
                    tmp += 1
                    res = max(res, x)
        return res
        