class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        cheapest = prices[0]

        for val in prices:
            res = max(res, val - cheapest)
            cheapest = min(cheapest, val)
        return res
        