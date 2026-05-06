class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = nums[0];

        for(int i = 0; i <= farthest; i++){
            farthest = max(nums[i] + i, farthest);
            if(farthest >= nums.size() - 1){
                return true;
            }
        }
        return false;

    }
};
