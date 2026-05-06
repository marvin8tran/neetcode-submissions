class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char, int> seen;

        if(s.size() != t.size()){
            return false;
        }

        for(int i = 0; i < s.size(); i++){
            seen[s[i]]++;
            seen[t[i]]--;
        }

        for(auto& s : seen){
            if(s.second != 0){
                return false;
            }
        }
        return true;
    }
};
