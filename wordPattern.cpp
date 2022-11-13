class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> words;
        int i = 0;
        while(i<s.length()) {
            string currStr = "";
            while(i < s.length() && s[i] != ' ') {
                currStr += s[i];
                i++;
            }
            i++;
            words.push_back(currStr);
        }
        if(pattern.length() != words.size())    
            return false;
        
        unordered_map<char, string> c2s;
        unordered_map<string, bool> s2b; 
        int j = 0;
        for(int i=0; i<pattern.length(); ++i) {
            char key = pattern[i];
            
            if(c2s.find(key) == c2s.end()) {
                if(s2b[words[i]] == true) {
                    return false;
                }
                else {
                    c2s[key] = words[i];
                    s2b[words[i]] = true;
                }
            } else {
                if(c2s[key] != words[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};