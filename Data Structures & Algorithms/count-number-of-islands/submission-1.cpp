class Solution {
int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int islands = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
    void bfs(vector<vector<char>>& grid, int r, int c){
        queue<pair<int, int>> queue;
        //coords
        queue.push({r,c});
        grid[r][c] = '0';
        
        while(!queue.empty()){
            auto node = queue.front();
            queue.pop();

            int row = node.first;
            int col = node.second;

            for(int i = 0; i < 4; i++){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1'){
                queue.push({nr, nc});
                grid[nr][nc] = '0';
            }
            }
        }





    }

};
