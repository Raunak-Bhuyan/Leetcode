class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        // Define the possible directions for movement (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int current_row = q.front().first;
            int current_col = q.front().second;
            q.pop();

            for (auto direction : directions) {
                int new_row = current_row + direction.first;
                int new_col = current_col + direction.second;

                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m 
                    && grid[new_row][new_col] == '1' && !vis[new_row][new_col]) {
                    vis[new_row][new_col] = 1;
                    q.push({new_row, new_col});
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
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }
};