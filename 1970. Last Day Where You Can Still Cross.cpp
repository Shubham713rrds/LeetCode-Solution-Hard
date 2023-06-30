class Solution {
public:
    //TC-->O(row*col*log(cells.size()))  //SC-->O(row*col)
    bool solve(int mid, vector<vector<int>>&cells, int row, int col){
        vector<vector<bool>>grid(row, vector<bool>(col, 0));
        for(int i=0;i<mid;i++){
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }
        
        queue<pair<int,int>>q;
        for(int i=0;i<col;i++){
            if(grid[0][i]==0){
                q.push({0, i});
                grid[0][i]=1;  //marked as visited
            }
        }
        vector<int>dirs={0,1,0,-1,0};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==row-1)return true;

            for(int i=0;i<4;i++){
               int nx=x+dirs[i], ny=y+dirs[i+1];
               if(nx<0 || nx>=row || ny<0 || ny>=col || grid[nx][ny]==1)continue;
               grid[nx][ny]=1;
               q.push({nx, ny});
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans=0;
        int low=1, high=cells.size();
        while(low<=high){
           int mid=low+(high-low)/2;
           if(solve(mid, cells, row, col)){
               ans=mid;
               low=mid+1;
           }
           else{
               high=mid-1;
           }
        }
        return ans;
    }
};
