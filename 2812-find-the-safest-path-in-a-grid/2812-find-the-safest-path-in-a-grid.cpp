class Solution {
public:
    int n, dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

    bool check(vector<vector<int>>& d, int x){
        if(d[0][0] < x) return false;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n));
        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty()){
            auto [r,c]=q.front(); q.pop();
            if(r==n-1 && c==n-1) return true;

            for(int k=0;k<4;k++){
                int nr=r+dx[k], nc=c+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<n &&
                   !vis[nr][nc] && d[nr][nc]>=x){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>> d(n, vector<int>(n,1e9));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]){
                    d[i][j]=0;
                    q.push({i,j});
                }

        while(!q.empty()){
            auto [r,c]=q.front(); q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dx[k], nc=c+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<n &&
                   d[nr][nc]>d[r][c]+1){
                    d[nr][nc]=d[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }

        int l=0,h=2*n,ans=0;
        while(l<=h){
            int m=(l+h)/2;
            if(check(d,m)) ans=m,l=m+1;
            else h=m-1;
        }
        return ans;
    }
};