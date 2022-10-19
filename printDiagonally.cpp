vector<int> downwardDigonal(int n, vector<vector<int>> mat) {
    // Your code goes here
	
    vector<int> ans;
    for(int i=0; i<n; ++i) {
        int row = 0;
        int col = i;
        
        while(row < n && col >= 0) {
            ans.push_back(mat[row][col]);
            row++;
            col--;
        }
    }
    for(int i=1; i<n; ++i) {
        int row = i;
        int col = n - 1;
        
        while(row < n && col >= 0) {
            ans.push_back(mat[row][col]);
            row++;
            col--;
        }
    }
    return ans;
}