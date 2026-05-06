class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> res(nums.size(), 1);


        int sum = 1;

        for(int i = 0; i < nums.size(); i++){
            res[i] *= sum;
            sum *= nums[i];
        }
        sum = 1;

        for(int i = nums.size() - 1; i >= 0; i--){
            res[i] *= sum;
            sum *= nums[i];
        }
        //0 = 2 * 4 * 6

        return res;

    }
};
