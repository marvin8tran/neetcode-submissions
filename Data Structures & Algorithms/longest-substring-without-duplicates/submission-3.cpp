class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_map<char, int> seen;
        for(int r = 0; r < s.size(); r++){
            while(seen[s[r]] != 0){ //unseen
                seen[s[l]]--;
                l++;
            }
            seen[s[r]]++;
            res = max(res, r - l +1);
        }

        return res;
        
    }
};
