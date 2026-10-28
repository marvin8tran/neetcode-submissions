class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        
        #c -> a -> t
        #c -> r -> a -> b -> t ->
        #if letter start doesnt match, move one letter down?
        #c matches, a and r dont match, skip r (or just track longest=1)
        #a matches, t doesn,t match, move on
        #after, repeat with starting a instead

        #index of curr letter text1, index i of text2 = longest we've seen so far
        #ITERATION IS 
        #check every text2 with text1 first char
        #add text2 with new text1 char just added
        #cases of abc
        #babubble
        #010000
        #10

        #dp[i1][i2] = longest seen  so far
        #iterate i1, check chars in i2 if match, else

        rows = len(text1)
        cols = len(text2)

        dp = [[0] * (cols+1) for _ in range(rows+1)]
        dp[0][0] = 0
        for i in range(1, rows+1):
            for j in range(1, cols+1): #i is constant, j iterating
                if text1[i-1] == text2[j-1]:
                    dp[i][j] += 1 + dp[i-1][j-1] #prev max without i + char
                else: 
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])
                    #dp[i-1][j] = val WITHOUT one letter
                    #dp[i][j-1] = VAL WITHOUT OTHER LETTER
                    #guarantee we always have both processed before?

                    #c > a > t
                    #c > r > a > b > t

                #NEED TO MAKE IT THE MAX HERE


        return dp[rows][cols]


        