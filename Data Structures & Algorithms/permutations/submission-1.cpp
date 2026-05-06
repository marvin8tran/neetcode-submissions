class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        unordered_map<int, int> freq;
        vector<vector<int>> res;
        vector<int> subset;
        for(int n : nums) freq[n]++;
        int s = nums.size();
        backtrack(subset, res, freq, s);
        return res;
        
    }

    void backtrack(vector<int>& subset, vector<vector<int>>& res, unordered_map<int, int>& freq, int size){
        if(subset.size() == size){
            res.push_back(subset);
            return;
        }

        for(auto& [n, count] : freq){
            if(freq[n] >  0){
                subset.push_back(n);
                freq[n]--;
                backtrack(subset, res, freq, size);
                freq[n]++;
                subset.pop_back();
            }
            
        }

        return;

    }
};
