class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int res = max(nums[0], nums[1]);
        int a = nums[0];
        int b = nums[1];
        int c = nums[2] + nums[0];
        

        for(int i = 3; i < nums.size(); i++){
            res = max(a, b);
            res += nums[i];
            a = b;
            b = c;
            c = max(res,c);
        }

        return max(res, c);
    }
};
