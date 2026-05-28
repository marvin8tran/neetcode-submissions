class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //true if new letter can split prev letters true
        unordered_set<string> dict;
        for(string s : wordDict){
            dict.insert(s);
        }
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && dict.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
