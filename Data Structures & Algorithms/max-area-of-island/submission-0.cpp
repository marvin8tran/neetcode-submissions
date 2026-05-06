class Solution {
private:
    int directions[4][2] = {{0, 1}, {0, -1}, {1,0}, {-1, 0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxRes = 0;


        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if (grid[r][c] == 1) {
                    maxRes = max(maxRes, maxdfs(grid, r, c));
                }
            }
        }
        return maxRes;

    }

    int maxdfs(vector<vector<int>>& grid, int r, int c){

        if(r < 0 || c < 0 || r >= grid.size() || 
        c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        }

        int res = 1;
        grid[r][c] = 0;
        for(int i = 0; i < 4; i++){
            res += maxdfs(grid, r + directions[i][0], c + directions[i][1]);
        }

        return res;
    }

};
