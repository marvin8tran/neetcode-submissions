class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //kahn's algorithm

        vector<vector<int>> adj(numCourses); //adj list

        for(auto& e : prerequisites){
            adj[e[1]].push_back(e[0]); //course b comes before a
        }


        int n = adj.size();
        vector<int> indegree(n, 0);
        int topolsort = 0;

        for(int i = 0; i < n; i++){
            for(int j : adj[i]){ //this node points to all of these
                indegree[j]++; //# of nodes pointing into this node + 1
            }
        }


        queue<int> q;
        for(int k = 0; k < n; k++){
            if(indegree[k] == 0){q.push(k);}
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();
            topolsort++;

            for(int x : adj[top]){
                indegree[x]--;
                if(indegree[x] == 0){q.push(x);}
            }
        }

        return topolsort == n;
    }
};
