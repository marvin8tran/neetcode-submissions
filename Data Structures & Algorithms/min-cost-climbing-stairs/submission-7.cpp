class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int res = cost[1];
        int a = cost[0];
        int b = cost[1];
        
        for(int i = 2; i < cost.size(); i++){
            res = min(a, b);
            res += cost[i];
            a = b;
            b = res;
        }

        return min(res, a);
    }
};
