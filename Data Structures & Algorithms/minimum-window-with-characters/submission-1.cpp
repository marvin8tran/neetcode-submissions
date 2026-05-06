class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> req;
        unordered_map<char, int> window;


        for(char x : t){
            req[x]++;
        }

        int have = 0;
        int need = req.size();
        int resLen = INT_MAX;
        pair<int, int> res = {-1, -1};

        int l = 0;
        for(int r = 0; r < s.size(); r++){

            char c = s[r];
            window[c]++;

            if(req.count(c) && req[c] == window[c]){
                have++;
            }

            //shrink window
            while(have == need){
                if(r - l + 1 < resLen){
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if(req.count(s[l]) && window[s[l]] < req[s[l]]){
                    have--;
                }
                l++;
            }
        }

        if(resLen == INT_MAX){ return "";}
        return s.substr(res.first, resLen);



    }
};
