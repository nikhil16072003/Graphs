#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
class graph{
    public:
    unordered_map<int,list<int>>adj;
    void addedge(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<"\n";

        }
    }


};

int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;
   graph g;
   int i;
   for(i=0;i<m;i++){
    int u,v;
    cin>>u;
    cin>>v;
    g.addedge(u,v,0);
   
   }
    g.print();
   return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
adj matrix

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;
    int i,j;
    int adj[m][m];
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            adj[i][j]=0;
        }
        
    }
    for(i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
        
        
    }
}
