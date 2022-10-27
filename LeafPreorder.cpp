vector<int> leafNodes(int arr[],int N) {
    // code here
    
    vector<int> ans;

    stack<int> st;
    for(int i=0; i<N; ++i) {
        int count = 0;
        int leaf = -1;
        
        while(!st.empty() && st.top() < arr[i]) {
            if(leaf == -1)  leaf = st.top();
            count += 1;
            st.pop();
        }
        if(count >= 2)  ans.push_back(leaf);
        st.push(arr[i]);
    }
    ans.push_back(st.top());
    return ans;
}