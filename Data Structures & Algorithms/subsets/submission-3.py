class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        def bt(i: int, x: List[int]):
            res.append(x[:])
            for j in range(i, len(x)):
                temp = x.pop(j)
                bt(j, x)
                x.insert(j, temp)
        
        bt(0, nums)
        return res

