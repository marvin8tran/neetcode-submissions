class Solution {
public:
    void bfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& heights, queue<pair<int, int>>& q){
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            visited[row][col] = true;

            //level prolly dont matter
            for(int j = 0; j < 4; j++){
                int nr = row + dir[j][0];
                int nc = col + dir[j][1];

                if(nr >= 0 && nc >= 0 && nr <= r && nc <= c && 
                heights[nr][nc] >= heights[row][col] && !visited[nr][nc]){
                    visited[row][col] = true;
                    q.push({nr, nc});
                }
            }
        }

        return;

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size() - 1;
        int c = heights[0].size() - 1;
        //u just needa mark accessible by pacific or nah

        queue<pair<int, int>> q;

        for(int i = 0; i <= r; i++){ q.push({i, 0});} //left
        for(int i = 0; i <= c; i++){ q.push({0, i});} //top

        //mark by making it negative?
        vector<vector<bool>> seen(r+1, vector<bool>(c+1, false));
        vector<vector<bool>> seen2(r+1, vector<bool>(c+1, false));

        bfs(r, c, seen, heights, q);

        for(int i = 0; i <= r; i++){ q.push({i, c});} //right
        for(int i = 0; i <= c; i++){q.push({r, i});} //bot

        bfs(r, c, seen2, heights, q);


        vector<vector<int>> res;
        for(int i = 0; i <= r; i++){
            for(int j = 0; j <= c; j++){
                if(seen[i][j] && seen2[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};
