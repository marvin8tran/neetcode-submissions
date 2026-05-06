class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int farthest = nums[0];

        for(int i = 0; i < farthest; i++){
            if(farthest >= nums.size()){
                return true;
            }
            farthest = max(nums[i] + i + 1, farthest);
        }

        return false;

    }
};
