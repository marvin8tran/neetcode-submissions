class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        res = []
        subset = []


        def bt(i: int, total: int):
            if i >= len(nums) or total > target:
                return
            elif total == target:
                res.append(subset.copy())
                return
            
            subset.append(nums[i])
            bt(i, total + nums[i])
            subset.pop()
            bt(i+1, total)

        bt(0, 0)
        return res