class Solution {
public:
    void bt(int target, int sum, int idx, vector<int>& subset, vector<int>& nums, vector<vector<int>>& res){

        if(sum == target){
            res.push_back(subset);
            return;
        }
        if(sum > target){
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            subset.push_back(nums[i]);
            bt(target, sum + nums[i], i, subset, nums, res);
            subset.pop_back();
        }
        return;

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        bt(target, 0, 0, subset, nums, res);
        return res;
    }
};
