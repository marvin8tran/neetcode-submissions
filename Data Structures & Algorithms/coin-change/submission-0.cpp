class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //probably dp the amount used previously MINUS new coin
        vector<int> dp(amount+1, amount + 1);
        int res = -1;
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(int j : coins){
                if(j > i){continue;}
                
                dp[i] = min(dp[i], dp[i - j] + 1); //smallest = prev + coin value
            }
        }

        if(dp[amount] == amount+1){return -1;}
        return dp[amount];

    }
};
