class Solution {
public:

    void bt(int idx, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res){
        res.push_back(subset);

        for(int i = idx; i < nums.size(); i++){
            subset.push_back(nums[i]);
            bt(i + 1, nums, subset, res);
            subset.pop_back();
        }


    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        bt(0, nums, subset, res);
        return res;

    }
};
