class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //implement dijkstras lol

        vector<int> dist(n, INT_MAX);

        //adj list
        vector<vector<pair<int,int>>> adj(n);
        for(auto& p : times){
            adj[p[0]-1].push_back({p[1]-1, p[2]});     
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //Dijkstra's BFS?
        k--;
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if(d > dist[u]){continue;}

            for(auto& x : adj[u]){ //every node this visits
                int v = x.first;
                int weight = x.second;

                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        int res = 0;
        for(int q : dist){
            if(q == INT_MAX){return -1;}
            res = max(q, res);
        }
        return res;

    }
};
