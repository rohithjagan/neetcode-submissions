class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& heights,int r,int c,vector<vector<bool>>& vis){
        vis[r][c]=true;
        if(r+1<m && !vis[r+1][c] && heights[r+1][c]>=heights[r][c]){
            dfs(heights,r+1,c,vis);
        }
        if(r-1>=0 && !vis[r-1][c] && heights[r-1][c]>=heights[r][c]){
            dfs(heights,r-1,c,vis);
        }
        if(c+1<n && !vis[r][c+1] && heights[r][c+1]>=heights[r][c]){
            dfs(heights,r,c+1,vis);
        }
        if(c-1>=0 && !vis[r][c-1] && heights[r][c-1]>=heights[r][c]){
            dfs(heights,r,c-1,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));
        for(int c=0;c<n;c++){
            dfs(heights,0,c,pac);
        }
        for(int r=0;r<m;r++){
            dfs(heights,r,0,pac);
        }
        for(int c=0;c<n;c++){
            dfs(heights,m-1,c,atl);
        }
        for(int r=0;r<m;r++){
            dfs(heights,r,n-1,atl);
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
