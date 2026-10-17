class Solution:
    def jump(self, nums: List[int]) -> int:
        farthest = 0
        curr = 0
        jumps = 0
        for i in range(len(nums)-1):
            farthest = max(farthest, i + nums[i])
            if i == curr:
                jumps += 1
                curr = farthest
        return jumps
        