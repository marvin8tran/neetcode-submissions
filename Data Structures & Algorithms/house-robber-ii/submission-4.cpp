class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()){return 0;}
        if(nums.size() == 1){return nums[0];}
        int a = 0;
        int b = 0;
        for(int i = 1; i < nums.size(); i++){
            int tmp = b;
            b = max(a + nums[i], b);
            a = tmp;
        }

        int res = b;
        a = 0;
        b = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            int tmp = b;
            b = max(a + nums[i], b);
            a = tmp;
        }

        res = max(res, b);

        return res;
    }
};
