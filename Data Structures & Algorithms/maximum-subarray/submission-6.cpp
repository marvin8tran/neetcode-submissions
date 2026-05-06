class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int best = nums[0];
        for(int c : nums){
            sum += c;
            best = max(best, sum);
            if (sum < 0){
                sum = 0;
            }
        }

        return best;
    }
};

//if curr num better than past sum, reset

//if sum < 0, reset
