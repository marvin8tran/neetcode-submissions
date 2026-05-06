class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r){
                int sum = nums[l] + nums[r] + nums[i];
                if(sum == 0){
                    res.push_back({nums[l], nums[r], nums[i]});
                    while(nums[l] == nums[l+1]){
                        l++;
                    }
                    while(nums[r] == nums[r-1]){
                        r--;
                    }
                }
                if(sum < 0){
                    l++;
                } else{
                    r--;
                }
            }
        }
        return res;


    }
};
