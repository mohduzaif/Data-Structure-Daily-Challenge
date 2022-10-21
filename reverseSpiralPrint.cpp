vector<int> reverseSpiral(int row, int col, vector<vector<int>>&matrix)  {
        // code here

    vector<int> ans;

    int sr = 0;
    int er = row-1;
    int sc = 0;
    int ec = col-1;

    while(sr <= er && sc <= ec) {

        int i = sc;
        while(i <= ec) {
            ans.push_back(matrix[sr][i]);
            i++;
        }   
        sr++;

        i = sr;
        while(i <= er) {
            ans.push_back(matrix[i][ec]);
            i++;
        }
        ec--;

        i = ec;
        while(i >= sc && sr <= er) {
            ans.push_back(matrix[er][i]);
            i--;
        }
        er--;

        i = er;
        while(i >= sr && sc <= ec) {
            ans.push_back(matrix[i][sc]);
            i--;
        }
        sc++;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}