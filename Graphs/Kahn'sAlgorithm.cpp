class Solution {
public:
    vector<int> toposort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        
        // Compute the indegree of each node
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        // Push all nodes with indegree 0 into the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        // Perform BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return topo;
    }
};


