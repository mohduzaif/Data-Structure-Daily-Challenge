bool isToeplitzMatrix(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    for(int row = 0; row < m; ++row) {
        int ele = matrix[row][0];
        int i = row;
        for(int col = 0; col < n && i < m; ++col, ++i) {
            if(matrix[i][col] != ele)   
                return false;
        }
    }

    for(int col = 1; col < n; ++col) {
        int ele = matrix[0][col];
        int j = col;
        for(int row = 0; row < m && j < n; ++row, ++j) {
            if(matrix[row][j] != ele)
                return false;
        }
    }
    return true;
}