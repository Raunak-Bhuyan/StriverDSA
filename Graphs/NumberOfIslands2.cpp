class Solution {
  public:

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

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
       
       DisjointSet ds(n*m);
       int vis[n][m];
       memset(vis, 0, sizeof vis);
       int count = 0;
       vector<int> ans;
       for(auto it: operators){
           int row = it[0];
           int col = it[1];
           if(vis[row][col] == 1){
               ans.push_back(count); //no change in the count of island
               continue; //proceed to the next query
           }
           vis[row][col] = 1;
           count++;
           //row-1, col
           //row, col + 1
           //row+1, col
           //row, col - 1
           int dr[] = {-1,0,1,0};
           int dc[] = {0,-1,0,1};
           
           for(int i=0; i<4; i++){
               int nr = row + dr[i];
               int nc = col + dc[i];
               
               if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 1){
                   int nodeNumber = row*m + col;
                   int adjNodeNumber = nr*m + nc;
                   if(ds.findParent(nodeNumber) != ds.findParent(adjNodeNumber)){
                       count--;
                       ds.UnionBySize(nodeNumber, adjNodeNumber);
                   }
               }
           }
           ans.push_back(count);
       }
       return ans;
    }
};