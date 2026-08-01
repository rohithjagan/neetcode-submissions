class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        int minutes = 0;
        while(!q.empty() && fresh>0){
            int size = q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                if(r+1<rows && grid[r+1][c]==1){
                    grid[r+1][c]=2;
                    fresh--;
                    q.push({r+1,c});
                }
                if(r-1>=0 && grid[r-1][c]==1){
                    grid[r-1][c]=2;
                    fresh--;
                    q.push({r-1,c});
                }
                if(c+1<cols && grid[r][c+1]==1){
                    grid[r][c+1]=2;
                    fresh--;
                    q.push({r,c+1});
                }
                if(c-1>=0 && grid[r][c-1]==1){
                    grid[r][c-1]=2;
                    fresh--;
                    q.push({r,c-1});
                }
            }
            minutes++;
        }
        if(fresh>0){
            return -1;
        }
        return minutes;
    }
};
