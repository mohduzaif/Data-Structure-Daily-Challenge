bool compare(vector<int>& selected, string& currStr) {
    vector<int> selfCheck(26, 0);
    for(int i=0; i<currStr.length(); ++i) {
        if(selfCheck[currStr[i] - 'a'] == 1)    
            return false;
        selfCheck[currStr[i] - 'a'] = 1;
    }
    
    for(int i=0; i<currStr.length(); ++i) {
        if(selected[currStr[i] - 'a'] == 1)    return false;
    }
    return true;
}

int helper(int i, vector<int>& selected, vector<string>& arr, int len) {
    
    if(i == arr.size())
        return len;
    
    string currStr = arr[i];
    if(compare(selected, currStr) == false) {
        return helper(i+1, selected, arr, len);
    }else {
        //Pick the string
        for(int i=0; i<currStr.length(); ++i) {
            selected[currStr[i] - 'a'] = 1;
        }
        len += currStr.length();
        int op1 = helper(i+1, selected, arr, len);
        
        //Skip the string
        for(int i=0; i<currStr.length(); ++i) {
            selected[currStr[i] - 'a'] = 0;
        }
        len -= currStr.length();
        int op2 = helper(i+1, selected, arr, len);
        
        return max(op1, op2);
    }
}

int maxLength(vector<string>& arr) {
    vector<int> selected(26, 0);
    return helper(0, selected, arr, 0);
}
