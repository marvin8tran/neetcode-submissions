class Solution {
public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> dp;
        int n = nums.size() - 1;
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2] + nums[0];
        

        for(int i = 3; i <= n; i++){
            dp[i] = max(dp[i-2], dp[i-3]);
            dp[i] += nums[i];
        }

        return max(dp[n-1], dp[n]);
    }
};
