class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0); // (n + 1) size will help for both 0-based and 1-based indexing
        parent.resize(n + 1);
        size.resize(n+1);
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

    void UnionBySize(int u, int v){
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);
        if (ultimateParentU == ultimateParentV) return;
        if(size[ultimateParentU] < size[ultimateParentV]){
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV] += size[ultimateParentU];
        }else{
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];           
        }
    }
};  


class Solution{
    public: 
        int removeStones(vector<vector<int>>& stones){
            int n = stones.size();
            int maxRow = 0;
            int maxCol = 0;
            //For getting the dimension of the grid
            for(auto it: stones){
                maxRow = max(maxRow, it[0]);
                maxCol = max(maxCol, it[1]);
            }

            DisjointSet ds(maxRow + maxCol + 1);
            unordered_map<int, int> stoneNodes; //nodes where stones are present
            for(auto it: stones){
                int nodeRow = it[0];
                int nodeCol = it[1] + maxRow + 1; //shift: lastRowNumber + col + 1
                ds.UnionBySize(nodeRow, nodeCol); //nodes having stones are joined
                stoneNodes[nodeRow] = 1;
                stoneNodes[nodeCol] = 1;
            }

            int count = 0; //count of connected components
            for(auto it: stoneNodes){
                if(ds.findParent(it.first) == it.first){
                    count++;
                }
            }
            return n - count;
        }
};