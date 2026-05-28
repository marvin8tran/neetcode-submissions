class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currMin = 1;
        int currMax = 1;
        //max and min
        //when new number, neg * num (so min times min), max * num, or curr

        for(int n : nums){

            int tmp = currMax * n;
            currMax = max(max(n * currMin, n * currMax), n);
            currMin = min(min(n * currMin, tmp), n);
            
            res = max(currMax, res);
        }

        return res;


        
        
    }
};
