//TC-->O(N! * N)  SC-->O(N*N)
class Solution {
public:
    void solve(int n, int col, vector<string>&temp, vector<int>&leftCol, vector<int>&upperDiagonal, vector<int>&lowerDiagonal, int &cnt){
        if(col==n){
            cnt++;
            return;
        }

        for(int row=0;row<n;row++){
            if(leftCol[row]==0 && upperDiagonal[(n-1)+(col-row)]==0 && lowerDiagonal[row+col]==0){
                leftCol[row]=1;
                upperDiagonal[(n-1)+(col-row)]=1;
                lowerDiagonal[row+col]=1;
                temp[row][col]='Q';
                solve(n, col+1, temp, leftCol, upperDiagonal, lowerDiagonal, cnt);
                leftCol[row]=0;
                upperDiagonal[(n-1)+(col-row)]=0;
                lowerDiagonal[row+col]=0;
                temp[row][col]='.';
            }
        }
        return;
    }
    int totalNQueens(int n) {
        int cnt=0;
        vector<string>temp(n, string(n, '.'));
        
        vector<int>leftCol(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
        solve(n, 0, temp, leftCol, upperDiagonal, lowerDiagonal, cnt);
        return cnt;
    }
};
