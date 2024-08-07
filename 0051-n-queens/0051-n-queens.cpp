class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for (int i=0;i<n;i++){
            board[i] = s;
        }
        vector<int> leftRow(n,0), upperDiag(2*n-1, 0), lowerDiag(2*n-1, 0);

        nQueens(0, n, ans, board, leftRow, upperDiag, lowerDiag);
        return ans;
    }

    void nQueens(int col, int n, vector<vector<string>>&ans, vector<string>&board, vector<int>&leftRow, vector<int>&upperDiag, vector<int>&lowerDiag){
        if (col==n){
            ans.push_back(board);
            return;
        }

        for (int row=0; row<n;row++){
            if (leftRow[row]==0 && lowerDiag[row+col]==0 && upperDiag[n-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiag[row+col]=1;
                upperDiag[n-1+col-row]=1;
                nQueens(col+1, n, ans, board, leftRow, upperDiag, lowerDiag);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiag[row+col]=0;
                upperDiag[n-1+col-row]=0;
            }
        }
    }
};