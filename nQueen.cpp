class Solution {
    bool isSafePlace(int row, int col, int n, vector<vector<bool>> board) {

        int i = row;
        int j = col;
        while(i < n && j >= 0) {
            if(board[i][j])  return false;
            i++;
            j--;
        }

        i = row;
        j = col;
        while(j >= 0) {
            if(board[i][j])  return false;
            j--;
        }

        i = row;
        j = col;
        while(i >= 0 && j >= 0) {
            if(board[i][j])  return false;
            i--;
            j--;
        }

        return true;
    }

    int solve( int col, vector<vector<bool>> &board, int n) {

        if(col == n) {
            return 1;
        }

        int count = 0;
        for(int row=0; row < n; ++row) {
            if(isSafePlace(row, col, n, board)) {
                board[row][col] = true;
                count += solve(col+1, board, n);
                board[row][col] = false;
            }
        }
        return count;
    }  
public:
    int totalNQueens(int n) {
        
        vector<vector<bool>> board(n, vector<bool>(n, false));
        
        return solve(0, board, n);
        
    }
};