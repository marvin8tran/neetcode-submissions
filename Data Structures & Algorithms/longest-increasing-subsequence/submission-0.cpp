class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {


        vector<int> dp;

        for(int n : nums){
            if(dp.empty()){dp.push_back(n); continue;}
            //replace, find the first num bigger than n
            //if n bigger than all the nums, extend

            int l = 0;
            int r = dp.size() - 1;
            while(l < r){
                int mid = (l + r) / 2;
                if(dp[mid] < n){
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }

            if(dp[l] < n){
                dp.push_back(n);
            } else{
                dp[l] = n;
            }

        }

        return dp.size();
    }
};
