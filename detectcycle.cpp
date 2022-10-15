// the time complexity of union find algorithm is O(ElogV).
// by using dfs or bfs we can do it in O(E+V).

// We can also find the cycle in undirected graph by using Union find algorithm

// detect cycle in undirected graph using dfs

bool isCyclicUtil(int v, bool visited[], int parent)
{
 
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
 
        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if (!visited[*i]) {
            if (isCyclicUtil(*i, visited, v))
                return true;
        }
 
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (*i != parent)
            return true;
    }
    return false;
}
 
// Returns true if the graph contains
// a cycle, else false.
bool isCyclic()
{
 
    // Mark all the vertices as not
    // visited and not part of recursion
    // stack
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper
    // function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++) {
 
        // Don't recur for u if2
        // it is already visited
        if (!visited[u])
            if (isCyclicUtil(u, visited, -1))
                return true;
    }
    return false;
}



// detect cycle in undirected graph using bfs
bool isCyclicConntected(vector<int> adj[], int s,
                        int V, vector<bool>& visited)
{
    // Set parent vertex for every vertex as -1.
    vector<int> parent(V, -1);
 
    // Create a queue for BFS
    queue<int> q;
 
    // Mark the current node as
    // visited and enqueue it
    visited[s] = true;
    q.push(s);
 
    while (!q.empty()) {
 
        // Dequeue a vertex from queue and print it
        int u = q.front();
        q.pop();
 
        // Get all adjacent vertices of the dequeued
        // vertex u. If a adjacent has not been visited,
        // then mark it visited and enqueue it. We also
        // mark parent so that parent is not considered
        // for cycle.
        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                parent[v] = u;
            }
            else if (parent[u] != v)
                return true;
        }
    }
    return false;
}
 
bool isCyclicDisconntected(vector<int> adj[], int V)
{
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);
 
    for (int i = 0; i < V; i++)
        if (!visited[i] && isCyclicConntected(adj, i,
                                         V, visited))
            return true;
    return false;
}
 

// detect cycle in directed graph using dfs

bool  f(int node, vector<int> adj[],vector<int> &vis,vector<int> &path){
        path[node]=true;
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it] and f(it,adj,vis,stack)){
                return true;
                
            }
            if(path[it]){
                return true;
            }
        }
        path[node]=false;
        return false;
    }
  
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,false);
        vector<int> path(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i] and f(i,adj,vis,path)){
                return true;
            }
        }
        return false;
    }


// detect cycle using bfs in directed graph
// we use concept of topological sort here
// if count of visited nodes is equal to number of total nodes then there is not any cycle present in the graph

class Solution
{
    public:
        bool isCyclic(int V, vector<int> adj[])
        {
            vector<int> indegree(V, 0);

            for (int i = 0; i < V; i++)
            {
                for (int u: adj[i])
                {
                    indegree[u]++;
                }
            }
            queue<int> q;
            int cnt = 0;
            for (int i = 0; i < V; i++)
            {
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
            while (!q.empty())
            {
                int top = q.front();
                q.pop();
                cnt++;
                
                for (int u: adj[top])
                {
                    indegree[u]--;
                    if (indegree[u] == 0) q.push(u);
                }
            }
            
            return !(cnt == V);
        }
};