class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:

        res = []
        subset = []
        candidates = sorted(candidates)

        def bt(i: int, total: int):
            if total == target:
                res.append(subset.copy())
                return
            elif i >= len(candidates) or total > target:
                return
            subset.append(candidates[i])
            bt(i+1, total + candidates[i])
            tmp = subset.pop()
            while i < len(candidates) and tmp == candidates[i]:
                i += 1
            bt(i, total)

        bt(0, 0)
        return res