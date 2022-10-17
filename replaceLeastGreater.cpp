vector<int> findLeastGreater(vector<int>& arr, int n) {
        
      set<int> s;
      vector<int> ans(n, -1);
        
      for(int i=n-1; i >= 0; --i) {
            
          auto it = s.upper_bound(arr[i]);
          if(it != s.end())
              ans[i] = *it;
          s.insert(arr[i]);
        
      }   
      return ans;
}