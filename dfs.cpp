
#include <iostream>
using namespace std;
#include<vector>
void dfs(bool visited[],int n,vector<int>adj[],vector<int>&ans){
    ans.push_back(n);
    visited[n]=true;
    int i;
    for(auto i:adj[n]){
        if(visited[i]==false){
            dfs(visited,i,adj,ans);
        }
    }
    
}
int main() {
    int n;
    cin>>n;
    vector<int>ans;
    vector<int>adj[n];
    int i;
    for(i=0;i<n;i++){
        int u,v;
        cin>>u;
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool visited[n];
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    for(i=0;i<n;i++){
       if(visited[i]==0){
           dfs(visited,i,adj,ans);
       }
    }
 
  for(i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
  }
    

    return 0;
}
