class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:

        #index 1st, index 2 = longest length
        rows = len(text1)
        cols = len(text2)

        dp = [[0] * (cols+1) for _ in range(rows+1)]

        for i in range(1, rows+1):
            for j in range(1, cols+1):
                if text1[i-1] == text2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1] #1 + best without either char
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])
                    #best without char1, or char2
                    #cat
                    #crabt
                    #2, 2 a != r
                    #c match = dp[1][1]
                    # dp[2][1] = ca, c = 1
                    # dp[1][2] = c, cr = 1
        return dp[rows][cols]

        