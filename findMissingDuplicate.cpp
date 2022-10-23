vector<int> findErrorNums(vector<int>& nums) {
        
    vector<int> temp(nums.size(), 0);
    for(int i=0; i<nums.size(); ++i)
        temp[nums[i] - 1] += 1;
        
    vector<int> ans(2, -1);
    for(int i=0; i<temp.size(); ++i) {
        if(temp[i] == 2)
            ans[0] = i + 1;
        if(temp[i] == 0)
            ans[1] = i + 1;
    }
        
    return ans;
}