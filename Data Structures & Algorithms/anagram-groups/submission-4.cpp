class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> sorted;

        //check freq of each letter?
        //

        for(string curr : strs){

        vector<int> seen(26);
        for(char s : curr){
            seen[s-'a']++;
        }
        //unique key to group em all together
        //
        string key = to_string(seen[0]);
        for(int i = 1; i < 26; i++){
            key += "," + to_string(seen[i]);
        } 

        sorted[key].push_back(curr);

        //return 

        }

        vector<vector<string>> res;
        for(auto m : sorted){
            res.push_back(m.second);
        }

        return res;



    }
};
