#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>adj;
vector<int>vis,rec;

bool dfs(int u){
    vis[u]=1;
    rec[u]=1;

    for(int v:adj[u]){
        if(!vis[v]){
            if(dfs(v))return true;
        }
        else if(rec[v]){
            return true;
        }
    }

    rec[u]=0;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    int e;
    cin>>e;

    int total=n+m;
    adj.resize(total);
    vis.resize(total,0);
    rec.resize(total,0);

    for(int i=0;i<e;i++){
        int type,a,b;
        cin>>type>>a>>b;

        if(type==1){
            // Process -> Resource
            adj[a].push_back(n+b);
        }
        else{
            // Resource -> Process
            adj[n+a].push_back(b);
        }
    }

    bool cycle=false;

    for(int i=0;i<total;i++){
        if(!vis[i]){
            if(dfs(i)){
                cycle=true;
                break;
            }
        }
    }

    if(cycle)
        cout<<"Cycle detected!"<<endl;
    else
        cout<<"No cycle detected!"<<endl;

    return 0;
}