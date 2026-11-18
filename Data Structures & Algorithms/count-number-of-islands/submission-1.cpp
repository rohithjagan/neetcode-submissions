class Solution {
public:
    vector<pair<int,int>> dir = {
        {1,0}, {0,1}, {-1,0}, {0,-1}
    };

    void recurse(int i, int j,
                 vector<vector<int>>& visited,
                 vector<vector<char>>& grid) {

        visited[i][j] = 1;

        for(int d = 0; d < 4; d++) {

            int nr = i + dir[d].first;
            int nc = j + dir[d].second;

            // Check boundaries
            if(nr < 0 || nr >= grid.size() ||
               nc < 0 || nc >= grid[0].size()) {
                continue;
            }

            // Check whether the neighbour is unvisited land
            if(grid[nr][nc] == '1' && visited[nr][nc] == 0) {
                recurse(nr, nc, visited, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty() || grid[0].empty()) {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        int count = 0;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {

                if(grid[i][j] == '1' && visited[i][j] == 0) {

                    recurse(i, j, visited, grid);

                    count++;
                }
            }
        }

        return count;
    }
};