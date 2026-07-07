class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));

        int countFresh = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }

                if(grid[i][j]==1){
                    countFresh++;
                }
            }
        }

        int maxTime=0;

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty()){

            int row=q.front().first.first;
            int col=q.front().first.second;
            int tm=q.front().second;
            q.pop();

            maxTime=max(maxTime,tm);

            for(int i=0;i<4;i++){

                int r=row+drow[i];
                int c=col+dcol[i];

                if(r>=0 && r<m &&
                   c>=0 && c<n &&
                   grid[r][c]==1 &&
                   vis[r][c]!=2){

                    q.push({{r,c},tm+1});
                    vis[r][c]=2;
                    countFresh--;
                }
            }
        }

        if(countFresh!=0)
            return -1;

        return maxTime;
    }
};