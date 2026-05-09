class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& seen){
        if(seen[i]){return;}
        seen[i] = true;

        for(int k : adj[i]){
            dfs(k, adj, seen);
        }
        return;
    }


    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> seen(n, false);

        vector<vector<int>> adj(n);

        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int res = 0;
        
        for(int i = 0; i < n; i++){ //dfs every node
            if(seen[i]) continue;
            dfs(i, adj, seen);
            res++;
        }
        return res;
    }
};
