class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        #index i, buy/sell, max profit
        #after 1 row process, we got best price with purchase i
        #dp[i][j] = dp[value after j][new i] + new profit

        #dp[i][j] = max after NOT SELLING TODAY

        #but doesnt account for holding days?
        #dp[index][buy/sell] = max(sell now = buy, buy = subtract)

        rows = len(prices)

        dp = [[0] * 2 for _ in range(rows+1)]

        #   1  3  4  0  4
        #0  -1 -3 -4  -1 3
        #1  0  2   -3 1
        dp[0][1] = float('-inf')

        for i in range(1, rows+1):
            dp[i][0] = max(dp[i-1][1] + prices[i-1], dp[i-1][0])
            #maxprofit no stock = best holdingstockprofit + sell NOW 
            dp[i][1] = max(dp[i-2][0] - prices[i-1], dp[i-1][1])
            #maxprofit stock = best nostock - CHEAPEST BUY NOW, hold


        return dp[len(prices)][0]
        