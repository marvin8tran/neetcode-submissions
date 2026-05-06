class Solution {
public:
    vector<int> partitionLabels(string s) {
        int seen[26];

        for(int i = 0; i < s.size(); i++){
            seen[s[i] - 'a'] = i;
        }

        vector<int> res = {};
        int start = 0;
        int end = 0;
        for(int j = 0; j < s.size(); j++){
            end = max(end, seen[s[j] - 'a']);
            
            if(j == end){
                res.push_back(end - start + 1);
                start = j + 1;
            }
        }
        return res;
    }
};
