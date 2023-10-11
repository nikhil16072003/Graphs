class Solution {
public:
 bool bfs(int src, vector<vector<int>> g, vector<int> &col){
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto adj : g[node]){
                if(col[adj] == -1){
                    col[adj] = !col[node];
                    q.push(adj);
                }
                else if(col[adj] == col[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int src = 0;
        int n = graph.size();

        vector<int> col(n, -1);

        for(int i=0;i<n;i++){
            if(col[i] == -1){
                if(bfs(i, graph, col) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
