// Stores whether the vertex has been visited or not
vector <ll> visited;
// Adjacency list to store the graph
vector <vector <ll>> graph;

void dfs(ll v)
{
    visited[v]=1;
    for(auto x:graph[v])
    {
      if(visited[x]==0) dfs(x);
    }
    visited[v]=2;
}
