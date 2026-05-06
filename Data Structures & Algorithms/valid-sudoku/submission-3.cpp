class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        //row, values already here

        map<pair<int, int>, unordered_set<char>> squares;
        //box, values alr here

        //pairs 0,0  0,1, 0,2
        //      1,0  1,1  1,2
        //      etc

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                char currNum = board[r][c];
                if(currNum == '.') continue;
                pair<int, int> currSquare = {r / 3, c / 3};
                if(squares[currSquare].count(currNum)){
                    return false;
                }
                if(rows[r].count(currNum)){
                    return false;
                }
                if(cols[c].count(currNum)){
                    return false;
                }
                rows[r].insert(currNum);
                cols[c].insert(currNum);
                squares[currSquare].insert(currNum);
            }
        }
        return true;
        



    }
};
