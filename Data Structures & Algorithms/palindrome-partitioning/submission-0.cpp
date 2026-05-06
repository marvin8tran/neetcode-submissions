class Solution {
public:
    void bt(int idx, string& s, vector<string>& substr, vector<vector<string>>& res){
        if(idx >= s.size()){
            res.push_back(substr);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            //conditionpalindrome
            if(isPalindrome(s, idx, i)){
                substr.push_back(s.substr(idx, i - idx + 1));
                bt(i + 1, s, substr, res);
                substr.pop_back();
            }
            
        }
    }

    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subset;

        bt(0, s, subset, res);
        return res;
    }
};
