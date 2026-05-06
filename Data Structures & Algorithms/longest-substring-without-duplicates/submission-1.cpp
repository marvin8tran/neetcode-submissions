class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_map<char, int> seen;
        // char, appearance

        for(int r = 0; r < s.size(); r++){
            if(seen.count(s[r]) && seen[s[r]] >= l){
                l = seen[s[r]] + 1;
            }
            seen[s[r]] = r;
            res = max(r - l + 1, res);
        }
        return res;
    }
};
