class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int a = 0;
        int b = 0;

        for(int n : nums){
            int tmp = max(n + a, b);
            a = b;
            b = tmp;
        }

        int x = b;
        for(int n : nums){
            int tmp = max(n + a, b);
            a = b;
            b = tmp;
        }

        return b - x;

    }
};
