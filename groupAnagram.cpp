vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> umapp;

    for(string str : strs) {
        string temp = str;
        sort(str.begin(), str.end());
        umapp[str].push_back(temp);
    }

    for(pair<string, vector<string>> p : umapp) {
        vector<string> curr = p.second;
        ans.push_back(curr);
    }

    return ans;    
}