string makeGood(string s) {

    if(s.length() == 0 || s.length() == 1) return s;

    stack<char> st;
    for(char ch : s) {
        st.push(ch);
    }

    string ans = "";
    while(ans == "" && !st.empty()) {
        char ch1 = st.top();
        st.pop();
        char ch2 = st.top();
        st.pop();

        if(abs(int(ch1) - int(ch2)) == 32)    
            continue;
        else {
            ans = ch1 + ans;
            ans = ch2 + ans;
            // cout << abs(ch1 - ch2) << endl;
            // cout << int(ch1) << endl;
            // cout << int(ch2) << endl;
        }
    }

    while(!st.empty()) {
        char ch1 = st.top();
        st.pop();
        int ch2 = ans[0];
        if(abs(int(ch1) - int(ch2)) == 32) {
            ans.erase(0, 1);
        }
        else
            ans = ch1 + ans;
    }

    return ans;
}