class Solution {
public:
    //TC-->O(N! * N) SC-->O(N*N)
    void solve(int n, int row, vector<vector<string>>&ans, vector<string>&temp, vector<int>& upperCol, vector<int>&upperDiagonal, vector<int>&lowerDiagonal){
        if(row==n){
           ans.push_back(temp);
           return;
        }
        for(int col=0;col<n;col++){
            if(upperCol[col]==0 && upperDiagonal[n-1 +(col-row)]==0 && lowerDiagonal[row+col]==0){
                temp[row][col]='Q';
                upperCol[col]=1;
                upperDiagonal[n-1 +(col-row)]=1;
                lowerDiagonal[row+col]=1;
                solve(n, row+1, ans, temp, upperCol, upperDiagonal, lowerDiagonal);
                upperCol[col]=0;
                upperDiagonal[n-1 +(col-row)]=0;
                lowerDiagonal[row+col]=0;
                temp[row][col]='.';
            }
        }
         
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n, string(n,'.'));
        //upperdiagonal(n-1 +col -row) (chk upperleft)
        //   0 1 2 3 4
        // 0 4 5 6 7 8
        // 1 3 4 5 6 7
        // 2 2 3 4 5 6
        // 3 1 2 3 4 5
        // 4 0 1 2 3 4
  
        //lower diagonal(row+ col) (chk upper right)
        //   0 1 2 3 4
        // 0 0 1 2 3 4
        // 1 1 2 3 4 5
        // 2 2 3 4 5 6
        // 3 3 4 5 6 7
        // 4 4 5 6 7 8
          
        vector<int>upperCol(n, 0),upperDiagonal(2*n - 1, 0),lowerDiagonal(2*n - 1, 0);
        solve(n, 0, ans, temp, upperCol, upperDiagonal, lowerDiagonal);
        return ans;
    }
};
