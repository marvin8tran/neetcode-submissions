class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        //count what letters -> hashmap to a vector

       
        string key;

        for(const auto& s : strs){
            vector<int> seen(26, 0);
            for(char c : s){
                seen[c-'a']++;
            }
            string key = to_string(seen[0]);

            for(int i = 1; i < 26; i++){
                key += "," + to_string(seen[i]);
            }
            res[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (const auto& x : res){
            result.push_back(x.second);
        }

        return result;
        


    }
};
