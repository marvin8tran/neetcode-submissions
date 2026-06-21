class Solution {
public:
    string longestPalindrome(string s) {

        int res;
        int resL;

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for(int len = 1; len <= s.size(); len++){
            for(int i = 0; i <= s.size() - len; i++){
                int j = len + i - 1;


                if(i == j) {dp[i][j] = true;}
                else if(len <= 2){dp[i][j] = (s[i] == s[j]);}
                else if(s[i] == s[j] && dp[i+1][j-1]){dp[i][j] = true;}

                if(dp[i][j]){res = i; resL = len;}
            }
        }

        return s.substr(res, resL);
        
    }
};
