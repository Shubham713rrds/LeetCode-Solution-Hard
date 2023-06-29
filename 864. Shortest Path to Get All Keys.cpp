class Solution {
public:
    //TC-->O(n*m* 2^k) SC-->O()
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].size();
 
        int path=0, cntKey=0;
        vector<int>dirs={0, -1, 0, 1, 0};
        vector<vector<vector<bool>>>vis(m, vector<vector<bool>>(n, vector<bool>(1<<6, 0)));
    
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    q.push({i*n+j, 0});      //assuming n>m don't know why take another variable p=(n>m)?n:m; and use p in place of n 
                    vis[i][j][0]=1;
                }

                if(grid[i][j]>='a' && grid[i][j]<='f')cntKey++;
            }
        }
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
               int x=q.front().first/n, y=q.front().first%n;
               int carry=q.front().second;
               q.pop();
               cout<<carry<<" "<<path<<endl;
               if(carry==((1<<cntKey)-1))return path;

               for(int j=0;j<4;j++){
                   int nx=x+dirs[j], ny=y+dirs[j+1], k=carry;
                   if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]=='#')continue;

                   if(grid[nx][ny]>='a' && grid[nx][ny]<='f'){
                       k=carry|(1<<(grid[nx][ny]-'a'));
                   }
                   else if(grid[nx][ny]>='A' && grid[nx][ny]<='F'){
                       if(!(carry & (1<<(grid[nx][ny]-'A'))))continue;
                   }

                   if(!vis[nx][ny][k]){
                       vis[nx][ny][k]=1;
                       q.push({nx*n+ny, k});
                   }
               }
            }
            path++;
        }
        return -1;
    }
};
