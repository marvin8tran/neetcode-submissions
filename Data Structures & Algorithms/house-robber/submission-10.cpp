class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int a = nums[0];
        int b = max(nums[0], nums[1]);
        int res = b;

        for(int i = 2; i < nums.size(); i++){
            res = max(b, a + nums[i]);
            a = b;
            b = res;
        }

        return res;
        
    }
};
