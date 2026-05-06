class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        int sum = 0;
        for(int n : nums){
            sum += n;
            best = max(sum, best);
            if(sum < 0) sum = 0;
        }
        return best;
    }
};
