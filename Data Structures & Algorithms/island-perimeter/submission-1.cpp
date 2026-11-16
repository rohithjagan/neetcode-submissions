class Solution {
public:
    int count = 0;
    vector<pair<int,int>> dir = {
        {1,0}, {0,1}, {-1,0}, {0,-1}
    };
    void recurse(vector<vector<int>>& grid, int row, int col,
                 vector<vector<int>>& visited) {
        visited[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if (nr < 0 || nr >= grid.size() ||
                nc < 0 || nc >= grid[0].size()) {
                count++;
            }
            else if (grid[nr][nc] == 0) {
                count++;
            }
            else if (visited[nr][nc] == 0) {
                recurse(grid, nr, nc, visited);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    recurse(grid, i, j, visited);
                }
            }
        }
        return count;
    }
};