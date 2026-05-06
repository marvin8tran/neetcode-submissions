class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());

        backtrack(0, nums, subset, res);
        return res;
    }

    void backtrack(int idx, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res){
        res.push_back(subset);
        if(idx >= nums.size()){
            return;
        }
        
        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]){
            continue;
        }
            subset.push_back(nums[i]);
            backtrack(i + 1, nums, subset, res);
            subset.pop_back();
        }
        return;
    }
};
