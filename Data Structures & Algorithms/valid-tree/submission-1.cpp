class Solution {
public:
    void dfs(int idx, vector<vector<int>>& adj, vector<bool>& seen){
        seen[idx] = true;
        for(int n : adj[idx]){
            if(!seen[n]) dfs(n, adj, seen);
        }
        return;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        //there are n-1 edges, and all nodes are connected
        vector<bool> seen(n, false);
        vector<vector<int>> adj(n);

        if(edges.size() != n - 1){return false;}

        for(auto& u : edges){
            adj[u[0]].push_back(u[1]);
            adj[u[1]].push_back(u[0]);
        }

        dfs(0, adj, seen);

        for(bool x : seen){
            if(!x){return false;}
        }
        return true;

    }
};
