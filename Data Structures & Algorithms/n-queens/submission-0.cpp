class Solution {
public:

    void bt(int n, int placed, unordered_map<int, bool>& cols, unordered_map<int, bool>& diag, unordered_map<int, bool>& diag2, vector<string>& subset, vector<vector<string>>& res){

        if(placed == n){
            res.push_back(subset);
            return;
        }

        for(int i = 0; i < n; i++){
            if(cols[i]) continue;
            if(diag[placed+i]) continue;
            if(diag2[placed-i]) continue;
            string s(n, '.');
            s[i] = 'Q';
            diag[placed+i] = true;
            diag2[placed-i] = true;
            cols[i] = true;
            subset.push_back(s);
            bt(n, placed+1, cols, diag, diag2, subset, res);
            subset.pop_back();
            diag[placed+i] = false;
            diag2[placed-i] = false;
            cols[i] = false;
        }

        return;
    }

    

    vector<vector<string>> solveNQueens(int n) {

        //no diagonals, no straight, no column
        unordered_map<int, bool> cols;
        unordered_map<int, bool> diag;
        //row + col = bottomleft->topright
        // (2,1) (1,2) (3, 0) (0, 3)
        unordered_map<int, bool> diag2;
        //row - col topleft -> bottomright
        // (1,1) (0,0) (2,2) (3,3)
        // (0,2) (1,3)
        //NEGATIVE IS FINE, STILL UNIQUE
        vector<string> subset;
        vector<vector<string>> res;

        bt(n, 0, cols, diag, diag2, subset, res);
        return res;

        
    }
};
