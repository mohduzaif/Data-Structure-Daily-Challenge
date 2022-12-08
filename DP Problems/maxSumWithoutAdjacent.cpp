#include <iostream>
#include <vector>
using namespace std;

int getMaxSumTabular(vector<int> &nums) {
    int n = nums.size();

    vector<int> dp(n, 0);
    int prev2 = 0;
    int prev = nums[0];
    // dp[0] = nums[0];

    for(int i=1; i<n; ++i) {
        // int take = nums[i];
        int take = nums[i];
        if(i > 1)
            take += prev2;
        int notTake = 0 + prev;

        int curr = max(take, notTake);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int getMaxSumMemoization(vector<int> &nums, vector<int> &dp, int index) {

    if(index == 0)  return nums[0];
    if(index < 0)   return 0;

    if(dp[index] != -1) return dp[index];
    int take = nums[index] + getMaxSumMemoization(nums, dp, index-2);
    int notTake = 0 + getMaxSumMemoization(nums, dp, index-1);

    return dp[index] = max(take, notTake);
}

int getMaxSum(vector<int> &nums, int index) {

    if(index == 0)  return nums[index];
    if(index < 0)   return 0; 

    int take = nums[index] + getMaxSum(nums, index-2);
    int notTake = 0 + getMaxSum(nums, index-1);

    return max(take, notTake);
}

int main() {
    vector<int> nums = {2, 1, 7, 9};
    cout << getMaxSum(nums, nums.size()-1) << endl;

    vector<int> dp(nums.size(), -1);
    cout << getMaxSumMemoization(nums, dp, nums.size()-1) << endl;

    cout << getMaxSumTabular(nums) << endl;
    return 0;
}