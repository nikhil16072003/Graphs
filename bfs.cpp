#include<vector>
#include<queue>
#include <iostream>
using namespace std;
void bfs(vector<int>vi[],bool visited[],int node,vector<int>&ans){
    queue<int>q;
    visited[node]=1;
    q.push(node);
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for(auto i:vi[u]){
           if(visited[i]==false){
               q.push(i);
               visited[i]=true;
               
           }
            
        }
    }
}
void bfsin(vector<int>vi[],int n,vector<int>&ans){
    int i;
    bool visited[n];
    for(i=0;i<n;i++){
        visited[i]=false;
    }
    
    for(i=0;i<n;i++){
        if(visited[i]==false){
            bfs(vi,visited,i,ans);
        }
    }
}
void addedge(int u,int v,vector<int>vi[]){
    vi[u].push_back(v);
    vi[v].push_back(u);
}
int main() {
   int n;
   cin>>n;
   int i;
   vector<int>vi[n];
   vector<int>ans;
   for(i=0;i<n;i++){
       int u,v;
       cin>>u;
       cin>>v;
       addedge(u,v,vi);
   }
   bfsin(vi,n,ans);
   for(i=0;i<ans.size();i++){
       cout<<ans[i]<<" ";
   }
    return 0;
}
