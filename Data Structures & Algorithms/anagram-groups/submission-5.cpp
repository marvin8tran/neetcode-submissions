class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> keymap;

        for(string s : strs){
            vector<int> freq(26,0);
            for(char c : s){
                freq[c-'a']++;
            }

            string key = to_string(freq[0]);
            for(int i = 1; i < 26; i++){
                key += "," + to_string(freq[i]);
            }
            keymap[key].push_back(s);
        }

        for(const auto& x : keymap){
            res.push_back(x.second);
        }

        return res;
        
    }
};
