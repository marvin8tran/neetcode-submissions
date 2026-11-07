class Solution:
    def countBits(self, n: int) -> List[int]:

        #00, 01, 10, 11, 100, 
        #dp[i] = 1 + dp[i-offset]
        dp = [0] * (n+1)
        offset = 1

        #dp[i] = 1 (for power of 2) + leftover
        #100 = 1 + 00
        #11000 = 1 + 1000

        for i in range(1, n+1):
            if offset * 2 == i:
                offset = i
            dp[i] = 1 + dp[i-offset]
        return dp