class Solution {
public:
    bool backtrack(int idx, int r, int c, string& target, vector<vector<char>>& board){
        if(target.size() == idx){
            return true;
        }
        
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()){
            return false;
        }

        if(board[r][c] != target[idx]){
            return false;
        }


        board[r][c] = '#';

        bool res = backtrack(idx + 1, r + 1, c, target, board) ||
        backtrack(idx + 1, r - 1, c, target, board) ||
        backtrack(idx + 1, r, c + 1, target, board) ||
        backtrack(idx + 1, r, c - 1, target, board);

        board[r][c] = target[idx];

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(backtrack(0, r, c, word, board)){
                    return true;
                }
            }
        }
        return false;
        
    }
};
