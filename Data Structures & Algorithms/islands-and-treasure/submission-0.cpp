class Solution {
public:
    void dfs(int r, int c, int path, vector<vector<int>>& grid){

        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
            return;
        }

        if(path > grid[r][c]) return; //includes -1 case

        grid[r][c] = min(grid[r][c], path);

        dfs(r + 1, c, path + 1, grid);
        dfs(r - 1, c, path + 1, grid);
        dfs(r, c + 1, path + 1, grid);
        dfs(r, c - 1, path + 1, grid);

        return;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {

        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 0){
                    dfs(r, c, 0, grid);
                }
            }
        }
        return;
        
    }
};
