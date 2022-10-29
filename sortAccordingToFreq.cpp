string frequencySort(string s) {

    unordered_map<char, int> unmp;
    for(char ch : s)
        unmp[ch]++;

    priority_queue<pair<int, char> > maxHeap;
    for(auto [x, y]: unmp)
        maxHeap.push({y, x});

    string ans = "";
    while(!maxHeap.empty()) {
        pair<int, char> top = maxHeap.top();
        maxHeap.pop();
        for(int i=0; i<top.first; ++i)
            ans += top.second;
    }

    return ans;
}