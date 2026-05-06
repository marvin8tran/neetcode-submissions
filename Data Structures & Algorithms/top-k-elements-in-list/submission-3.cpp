class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //


        unordered_map<int, int> seen;

        for(int n : nums){
            seen[n]++;
        }
        //key = #, value = # it appears

        vector<vector<int>> freq(nums.size() + 1);
        for(auto& s : seen){
            freq[s.second].push_back(s.first);
        }

        vector<int> res;
        //index = appearance, int = #
        for(int i = freq.size() - 1; i>0; i--){
            for(int n : freq[i]){
                res.push_back(n);
            }
            if (res.size() == k){
                return res;
            }
        }

    }
};
