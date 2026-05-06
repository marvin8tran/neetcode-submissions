class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        backtrack(0, subset, nums, res);
        return res;
    }


    void backtrack(int index, vector<int>& subset, vector<int>& nums, vector<vector<int>>& res){
        res.push_back(subset);

        for(int i = index; i < nums.size(); i++){
            subset.push_back(nums[i]);
            backtrack(i + 1, subset, nums, res);
            subset.pop_back();
        }


    }
};
