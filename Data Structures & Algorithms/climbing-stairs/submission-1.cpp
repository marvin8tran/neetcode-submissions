class Solution {
public:
    int dp(int i){
        if(i <= 2) return i;
        return dp(i - 1) + dp(i - 2);
    }

    int climbStairs(int n) {
        return dp(n);
    }
};
