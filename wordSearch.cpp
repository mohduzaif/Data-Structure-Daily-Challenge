class Solution {
    bool search(vector<vector<char>> &board, string &word, int i, int j, int k, int m, int n) {
        
        if(k >= word.length())  return true;
        if(i < 0 || i == m || j < 0 || j == n || board[i][j] != word[k])    return false;
        
        board[i][j] = '#';
        
        bool top = search(board, word, i-1, j, k+1, m, n);
        bool bottom = search(board, word, i+1, j, k+1, m, n);
        bool left = search(board, word, i, j-1, k+1, m, n);
        bool right = search(board, word, i, j+1, k+1, m, n);
        
        board[i][j] = word[k];
        
        return (top || bottom || left || right);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(search(board, word, i, j, 0, m, n))
                    return true;
            }
        }
        
        return false;
    }
};