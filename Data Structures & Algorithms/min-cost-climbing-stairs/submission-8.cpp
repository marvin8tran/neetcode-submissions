class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if(cost.empty()){return 0;}
        if(cost.size() == 1) {return cost[0];}
        if(cost.size() == 2) {return  min(cost[0], cost[1]); }

        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++){
            dp[i] = min(dp[i-1], dp[i-2]);
            dp[i] += cost[i];
        }
        
        return min(dp[n-1], dp[n-2]);
    }
};
