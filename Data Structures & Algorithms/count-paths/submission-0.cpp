class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));

        //nvm, no reason to travers ebackwards
        dp[0][0] = 1;

        for(int i = 0; i < m; i++){ 
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){continue;}
                if(i == 0){ //left col
                    dp[i][j] = dp[i][j-1]; 
                } else if(j == 0){ //top row
                    dp[i][j] = dp[i-1][j];
                } else{
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }

        return dp[m-1][n-1];
    }
};
