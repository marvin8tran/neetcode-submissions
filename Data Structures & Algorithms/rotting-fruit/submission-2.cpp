class Solution {
int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        //bfs, count how many layers

        //rot least time?



        int res = 0;
        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){ q.push({i, j}); }
                if(grid[i][j] == 1){ fresh++; }
            }
        }

        if(fresh == 0){return 0;}

        while(!q.empty()){
            int currLength = q.size();
            res++;
            for(int i = 0; i < currLength; i++){
                auto [row, col] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int nr = row + direction[j][0];
                    int nc = col + direction[j][1];
                    if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size()
                && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh--;
                }
                }
            }
            
        }
        return fresh == 0 ? res - 1 : -1;
    }

};
