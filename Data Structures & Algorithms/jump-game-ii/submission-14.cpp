class Solution {
public:
    int jump(vector<int>& nums) {
        int maxJump = -1;
        int curr = 0;
        int totalJumps = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            maxJump = max(maxJump, nums[i] + i);
            if(i == curr){
                curr = maxJump;
                totalJumps++;
            }
        }
        return totalJumps;
    }
};
