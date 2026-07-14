class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>& grid, vector<vector<bool>>&vis,int drow[],int dcol[]){
        if(vis[i][j]){
            return;
        }
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int r=i+drow[k];
            int c=j+dcol[k];
            if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1 && !vis[r][c]){
                dfs(r,c,grid,vis,drow,dcol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        int drow[]={1,0,-1,0};
        int dcol[]={0,-1,0,1};
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid,vis,drow,dcol);
            }
            if(grid[m-1][i]==1){
                dfs(m-1,i,grid,vis,drow,dcol);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,vis,drow,dcol);
            }
            if(grid[i][n-1]==1){
                dfs(i,n-1,grid,vis,drow,dcol);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};