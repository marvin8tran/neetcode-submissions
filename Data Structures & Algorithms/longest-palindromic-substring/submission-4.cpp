class Solution {
private:
    int expand(string s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }

        return r - l - 1;

    }
public:
    string longestPalindrome(string s) {
        //longest substring = longest w/ left vs longest w/ right
        int res = 0;
        int resI = 0;
        for(int i = 0; i < s.size(); i++){
            int odd = expand(s, i, i);
            int even = expand(s, i, i+1);
            int len = max(odd, even);

            if(len > res){
                res = len;
                resI = i - (len - 1) /2; //start index = center - half length found

            }
            
        }

        return s.substr(resI, res);
        

    }
};
