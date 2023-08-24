
//lowest common Ancestor 
// Distances of Nodes

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int u=0,v=0;
void dfs(int u,int p,vector<int>& visted,vector<int> adj[],vector<int>& depth,vector<int>& nodes){
    visted[u]=1;
   // cout<<u+1<<" , ";
    nodes.push_back(u);
    for(auto v:adj[u]){
        if(!visted[v]){
            depth[v]+=depth[u];
            dfs(v,u,visted,adj,depth,nodes);
        }
    }
    if(p!=-1){ 
       // cout<<p+1<<" , ";
        nodes.push_back(p);
    }
}
int main()
{
    
    int n=8;
    vector<int> adj[n],depth(n,1),visted(n,0),nodes;
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[1].push_back(4);
    adj[1].push_back(5);
    adj[2].push_back(0);
    adj[3].push_back(0);
    adj[3].push_back(6);
    adj[4].push_back(1);
    adj[5].push_back(1);
    adj[5].push_back(7);
    adj[6].push_back(3);
    adj[7].push_back(5);
    dfs(0,-1,visted,adj,depth,nodes);
    cout<<endl;
    int a=7,b=6,x=-1,y=-1,ans=INT_MAX,ances=-1;
    
    for(int i=0;i<2*n-1;i++){
        //cout<<nodes[i]<<endl;
        if(nodes[i]==a){
            x=i;
        }
        if(nodes[i]==b){
            y=i;
        }
    }
    if(y<x) swap(x,y);
    for(auto i=x+1;i<y;i++){ 
        if(depth[nodes[i]]<ans){
            ans=depth[nodes[i]];
            ances=nodes[i];
        }
    }

    cout<<"Distances between  Nodes A and B ="<<depth[nodes[x]]+depth[nodes[y]]-2*depth[ances]<<endl;
    cout<<"Lowest Common Ancestor = "<<ances<<endl;
    return 0;
}
