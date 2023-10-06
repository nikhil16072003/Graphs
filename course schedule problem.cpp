class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }

        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }

        return ans.size()==n;
    }
};
