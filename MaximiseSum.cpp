    int maximizeSum(int arr[], int n) {
        
        unordered_map<int, int> unmp;
        for(int i=0; i<n; ++i)
            unmp[arr[i]]++;
        
        int ans = 0;
        for(int i=n-1; i>=0; --i) {
            if(unmp.find(arr[i]) != unmp.end()) {
                ans += arr[i];
                unmp[arr[i]]--;
                if(unmp[arr[i]] == 0) 
                    unmp.erase(arr[i]);
                
                if(unmp.find(arr[i]-1) != unmp.end()) {
                    unmp[arr[i]-1]--;
                    if(unmp[arr[i]-1] == 0)
                        unmp.erase(arr[i]-1);
                }
            }
        }
        return ans;
    }