class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for(int i : nums){
            if(!m[i]){
                m[i] = m[i + 1] + m[i - 1] + 1;
                m[i + m[i + 1]] = m[i];
                m[i - m[i - 1]] = m[i];
                res = max(res, m[i]);
            }
        }
        return res;


    }
};
