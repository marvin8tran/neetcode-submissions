class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while(l < r){
            if(l < r && !isalnum(s[l])){l++; continue;}
            if(l < r && !isalnum(s[r])){r--; continue;}
            if(tolower(s[l]) != tolower(s[r])){return false;}
            l++; r--;
        }
        return true;
    }
};
