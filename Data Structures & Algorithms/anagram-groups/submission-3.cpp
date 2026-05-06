class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        //string = 0,1,... letters, vector = words
        
        
        for(auto& s : strs){
            vector<int> count(26, 0);
            for(char& c : s){
                count[c-'a']++;
            }


            string key = to_string(count[0]);
            for(int i = 1; i < 26; i++){
                key += "," + to_string(count[i]);
            }

            group[key].push_back(s);

        }

        vector<vector<string>> result;
        for(auto& x : group){
            result.push_back(x.second);
        }

        return result;
        


    }
};
