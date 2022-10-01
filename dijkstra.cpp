#include <bits/stdc++.h>
using namespace std;

//bfs ,dijkstra algorithm ,find shortest path from source node 
// tc=o(nlog(n)
// sc=o(n)
void shortestpath(vector<vector<pair<int,int>>> &adj,vector<int> &dis,int source)
{
    priority_queue< pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>> > qt; 
    qt.push({0,source});
    dis[source]=0;
    while(!qt.empty())
    {
        int distance=qt.top().first;
        int u=qt.top().second;
        int size=qt.size();
        qt.pop();
        for(auto edge:adj[u])
        {
            int v=edge.first;
            int w=edge.second;
            if(dis[v]>(distance+w))
            {
                dis[v]=distance+w;
                qt.push({dis[v],v});
            }
        }
    }
}
int main()
{
    int n,m,source;cin>>n>>m>>source;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,w;cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    vector<int> dis(n+1,INT_MAX);
    shortestpath(adj,dis,source);
    for(int i=1;i<n+1;i++)
    {
        cout<<"distance from "<<source<<" -> "<<i<<" = "<<dis[i]<<endl; 
    }
}  
