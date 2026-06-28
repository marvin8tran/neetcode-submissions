class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //its probably surrounded if NOT TOUCHING EDGE

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> surr(m, vector<bool>(n, false)); //true = edge

        queue<pair<int, int>> coord;

        for(int k = 0; k < m; k++){
            coord.push({k,0});
            coord.push({k, n-1});
        }

        for(int l = 0; l < n; l++){
            coord.push({0, l});
            coord.push({m-1, l});
        }


        while(!coord.empty()){
            int x = coord.front().first;
            int y = coord.front().second;
            coord.pop();

            if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == 'X'){
                continue;
            }
            if(!surr[x][y] && board[x][y] == 'O'){
                surr[x][y] = true;
                coord.push({x+1, y});
                coord.push({x-1, y});
                coord.push({x, y+1});
                coord.push({x, y-1});
            }
            
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!surr[i][j] && board[i][j] == 'O'){board[i][j] = 'X';}
            }
        }

        return;




    }
};
