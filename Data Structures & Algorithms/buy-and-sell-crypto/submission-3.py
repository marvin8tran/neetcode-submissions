class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        hold = prices[0]
        for val in prices:
            res = max(res, val - hold)
            hold = min(hold, val)
        return res