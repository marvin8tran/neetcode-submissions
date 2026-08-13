class Solution {
public:
    void spread(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){return;}
        if(grid[r][c] == '0'){return;}
        grid[r][c] = '0';
        spread(grid, r+1, c);
        spread(grid, r-1, c);
        spread(grid, r, c+1);
        spread(grid, r, c-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == '1'){
                    islands++;
                    spread(grid, r, c);
                }
            }
        }
        return islands;
    }
};
