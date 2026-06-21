class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n : nums){ sum += n;}
        if(sum % 2 != 0){return false;}
        sum /= 2;

        vector<bool> dp(sum+1, false);
        dp[0] = true;

        for(int n : nums){
            for(int j = sum; j >= n; j--){
                if(dp[j-n]){
                    dp[j] = true;
                }
            }

        }

        return dp[sum];

    }
};
