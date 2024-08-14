#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0); // (n + 1) size will help for both 0-based and 1-based indexing
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void UnionByRank(int u, int v) {
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);
        if (ultimateParentU == ultimateParentV) return;
        if (rank[ultimateParentU] < rank[ultimateParentV]) {
            parent[ultimateParentU] = ultimateParentV; // path compression
        } else if (rank[ultimateParentV] < rank[ultimateParentU]) {
            parent[ultimateParentV] = ultimateParentU;
        } else {
            parent[ultimateParentV] = ultimateParentU; // converse is also true
            rank[ultimateParentU]++;
        }
    }

    void UnionBySize(int u, int v) {
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);
        if (ultimateParentU == ultimateParentV) return;
        if (size[ultimateParentU] < size[ultimateParentV]) {
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV] += size[ultimateParentU];
        } else {
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        
        // Using set to track unique edges
        //vector<set<pair<int, int>>> uniqueEdges(V);

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                // Ensure each edge is only added once
                /*if (uniqueEdges[i].find({wt, adjNode}) == uniqueEdges[i].end() && uniqueEdges[adjNode].find({wt, node}) == uniqueEdges[adjNode].end()) {
                    uniqueEdges[i].insert({wt, adjNode});*/
                    edges.push_back({wt, {node, adjNode}});
                }
            }
        }

        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findParent(u) != ds.findParent(v)) {
                mstWt += wt;
                ds.UnionBySize(u, v);
            }
        }
        return mstWt;
    }
};
