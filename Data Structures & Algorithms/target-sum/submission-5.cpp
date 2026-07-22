class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        //dp[value] = # of ways to get there
        dp[0] = 1;

        for(int n : nums){
            unordered_map<int, int> next;
            for(auto& [val, path] : dp){
                next[val + n] += path;
                next[val - n] += path;
            }
            dp = std::move(next);
        }
        return dp.count(target) ? dp[target] : 0;
    }
};
