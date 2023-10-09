#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    int s,t;
    cin>>s;
    cin>>t;
    int i;
    vector<int>adj[n];
    for(i=0;i<n;i++){
        int u,v;
        cin>>u;
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>parent;
    bool visited[n];
    for(i=0;i<n;i++){
        visited[i]=false;
    }
    
    vector<int>ans;
    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(q.empty()==false){
        int fr=q.front();
        q.pop();
        for(auto i:adj[fr]){
            if(visited[i]==false){
                  parent[i]=fr;
                  q.push(i);
                  visited[i]=true;
                
            }
          
        }
    }
    int current=t;
    ans.push_back(t);
    while(current!=s){
        current=parent[current];
        ans.push_back(current);
    }
    
    for(i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
