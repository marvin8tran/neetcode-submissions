class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(int n : nums){sum += n;}
        if(sum % 2 != 0){return false;}
        sum /= 2;

        vector<bool> dp(sum+1, false);
        dp[0] = true; //empty set

        for(int n : nums){
            for(int j = sum; j >= n; j--){ //for every possible sum created by adding n
                dp[j] = dp[j] || dp[j-n]; //stay true || turn true if possible to reach from adding n
            }
        }

        return dp[sum];



    }
};
