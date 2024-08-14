class Solution {
public:
    void bfs(int row, int columns, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        vis[row][columns] = 1;
        queue<pair<int, int>> q;
        q.push({row, columns});
        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            int current_row = q.front().first;
            int current_column = q.front().second;
            q.pop();

            for (int delRow = -1; delRow <= 1; delRow++) {
                for (int delCol = -1; delCol <= 1; delCol++) {
                    int neighbour_row = current_row + delRow;
                    int neighbour_column = current_column + delCol;
                    if (neighbour_row >= 0 && neighbour_row < n && neighbour_column >= 0 && neighbour_column < m 
                    && grid[neighbour_row][neighbour_column] == '1' && !vis[neighbour_row][neighbour_column]) {
                        vis[neighbour_row][neighbour_column] = 1;
                        q.push({neighbour_row, neighbour_column});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for (int row = 0; row < n; row++) {
            for (int columns = 0; columns < m; columns++) { // Corrected condition here
                if (!vis[row][columns] && grid[row][columns] == '1') {
                    count++;
                    bfs(row, columns, vis, grid);
                }
            }
        }
        return count;
    }
};