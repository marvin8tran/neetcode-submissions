class Solution {
public:
    int jump(vector<int>& nums) {
        int reach = 0;
        int best = 0;
        int jumps = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            best = max(best, nums[i] + i);
            if(i == reach){
                reach = best;
                jumps++;
            }
        }
        return jumps;
    }
};
