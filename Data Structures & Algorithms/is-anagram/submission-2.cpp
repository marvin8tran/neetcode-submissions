class Solution {
public:
    bool isAnagram(string s, string t) {
        
        
        if(s.size() != t.size()){
            return false;
        }

        vector<int> seen(26, 0);

        for(int i = 0; i < s.size(); i++){
            seen[s[i] - 'a']++;
            seen[t[i] - 'a']--;
        }

        for(int k = 0; k < 26; k++){
            if(seen[k] != 0){
                return false;
            }
        }

        return true;




    }
};
