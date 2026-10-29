class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        rows = len(prices)

        # dp[i][0] = best cash at end of day i, NOT holding
        # dp[i][1] = best cash at end of day i, holding a share
        dp = [[0] * 2 for _ in range(rows + 1)]
        dp[0][1] = float('-inf')  # can't hold a share before day 1

        for i in range(1, rows + 1):
            # not holding: rest, or sell the share I held yesterday
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1])

            # holding: keep holding, or buy today
            # buying needs a rest day yesterday, so use the not-holding value from i-2
            # (on day 1 there's no i-2, so we start from 0 cash)
            free_cash = dp[i-2][0] if i >= 2 else 0
            dp[i][1] = max(dp[i-1][1], free_cash - prices[i-1])

        return dp[rows][0]