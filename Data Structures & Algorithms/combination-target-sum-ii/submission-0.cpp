class Solution {
public:
    void backtrack( int sum, int target, int idx, vector<int>& candidates, vector<int>& subset, vector<vector<int>>& res){
        if(sum == target){
            res.push_back(subset);
            return;            
        }

        if(sum > target){
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }
            subset.push_back(candidates[i]);
            backtrack(sum + candidates[i], target, i + 1, candidates, subset, res);
            subset.pop_back();
            
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, 0, candidates, subset, res);
        return res;
    }
};
