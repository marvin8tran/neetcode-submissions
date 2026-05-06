class Solution {
public:

    void backtrack(int l, int r, string& s, vector<string>& res){
        if(l == 0 && r == 0){
            res.push_back(s);
            return;
        }

        if(l > 0){
            s.push_back('(');
            backtrack(l - 1, r, s, res);
            s.pop_back();
        }

        if(r > l){
            s.push_back(')');
            backtrack(l, r - 1, s, res);
            s.pop_back();
        }

        return;
    }


    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        backtrack(n, n, s, res);
        return res;
    }
};
