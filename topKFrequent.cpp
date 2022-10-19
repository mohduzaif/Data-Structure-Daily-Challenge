vector<string> topKFrequent(vector<string>& words, int k) {
        
    vector<string> ans;
    
    unordered_map<string, int> unmp;
    for(string str : words)
        unmp[str] += 1;
    
    vector<pair<int, string>> allString;
    
    for(pair<string, int> ele : unmp) {
        allString.push_back({-ele.second, ele.first}); 
    }
    
    sort(allString.begin(), allString.end());
    
    for(int i=0; i<k; ++i) {
        ans.push_back(allString[i].second);
    }
    
    return ans;
}