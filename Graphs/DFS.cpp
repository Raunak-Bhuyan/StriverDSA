class Solution{
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &dfsResult) {
        vis[node] = 1;
        dfsResult.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, dfsResult);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0}; // Initialize visited array with 0
        int start = 0; // Starting node for DFS
        vector<int> dfsResult; // Vector to store the DFS traversal
        dfs(start, adj, vis, dfsResult); // Call the private dfs function
        return dfsResult;
    }
};