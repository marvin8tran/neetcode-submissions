class Solution {
public:
    int dp(unordered_map<int, int>& cache, int i){
        if(i <= 2) return i;
        if(cache.count(i)) return cache[i];
        cache[i] = dp(cache, i-1) + dp(cache, i - 2);
        return cache[i];
    }

    int climbStairs(int n) {
        unordered_map<int, int> cache;
        return dp(cache, n);
    }
};
