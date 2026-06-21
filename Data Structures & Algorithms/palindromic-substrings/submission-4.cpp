class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        int res = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, 0));

        for(int len = 1; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = len + i - 1;
                if(i == j){dp[i][j] = true;} //length 1
                else if(len == 2){dp[i][j] = (s[i] == s[j]);}
                else if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                }

                if(dp[i][j]) res++;
            }
        }

        return res;
    }
};
