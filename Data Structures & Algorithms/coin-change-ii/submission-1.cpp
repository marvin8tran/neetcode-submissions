class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        //dp[coin] = shortest route to get here
        dp[0] = 1;
        //for every number, iterate through every denom to get routes
        for(int n : coins){
            for(int i = 1; i <= amount; i++){
                if(i > n){
                    dp[i] += dp[i - n];
                }
                if(i == n){
                    dp[i]++;
                }
            }
        }

        return dp[amount];
    }
};
