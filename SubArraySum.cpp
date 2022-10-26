bool checkSubarraySum(vector<int>& nums, int k) {
    
    int currSum = 0;
    int prevRem = 0;
    
    unordered_set<int> unmp;
    for(int i=0; i<nums.size(); ++i) {
        
        currSum += nums[i];
        int rem = currSum % k;
        
        if(unmp.find(rem) != unmp.end())
            return true;
        unmp.insert(prevRem);
        prevRem = rem;
    }
    return false;
}