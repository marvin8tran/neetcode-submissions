class Solution {
public:
    bool canJump(vector<int>& nums) {

       int reach = nums[0];


       for(int i = 0; i <= reach; i++){
            reach = max(reach, nums[i] + i);
            if(nums[i] + i >= nums.size() - 1){
                return true;
            }
       }
        return false;

    }
};
