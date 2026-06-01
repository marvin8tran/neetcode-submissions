class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = 1;
        int mn = 1;
        int res = nums[0];

        for(int n : nums){
            int tmp = mx;
            mx = max(max(mx * n, mn * n), n);
            mn = min(min(mn*n, tmp*n), n);
            res = max(res, mx);
        }

        return res;
    }
};
