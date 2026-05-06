class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int best = nums[0];
        for(int c : nums){
            if(sum < 0){
                sum = c;
            } else{
                sum += c;
            }
            best = max(best, sum);
        }

        return best;
    }
};

//if curr num better than past sum, reset

//if sum < 0, reset
