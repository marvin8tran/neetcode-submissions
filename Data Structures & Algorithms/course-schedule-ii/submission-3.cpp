class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);

        for(auto& e : prerequisites){
            adj[e[1]].push_back(e[0]);
        }

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(int child : adj[i]){
                indegree[child]++;
            }
        }

        queue<int> q;
        for(int k = 0; k < indegree.size(); k++){
            if(indegree[k] == 0){q.push(k);}
        }

        vector<int> res;


        while(!q.empty()){
            int top = q.front();
            q.pop();
            res.push_back(top);
            for(int next : adj[top]){
                indegree[next]--;
                if(indegree[next] == 0){q.push(next);}
            }
        }

        return res.size() == numCourses ? res : vector<int>{} ;


    }
};
