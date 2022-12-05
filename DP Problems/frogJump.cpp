#include <iostream>
#include <vector>
using namespace std;

// Recurrance relation function
int getMinimumEnergy(vector<int>& energy, int index) {

    if(index == 0)  return 0;

    int firstJump = getMinimumEnergy(energy, index-1) + abs(energy[index]-energy[index-1]);
    int secondJump = INT_MAX;
    if(index-2 >= 0)
        secondJump = getMinimumEnergy(energy, index-2) + abs(energy[index]-energy[index-2]);

    return min(firstJump, secondJump);
}

// Memoisation of recurance relation.
int getMinimumEnergyTopDown(vector<int>& energy, vector<int>& dp, int index) {

    if(index == 0)  return 0;

    if(dp[index] != -1)
        return dp[index];

    int firstJump = getMinimumEnergyTopDown(energy, dp, index-1) + abs(energy[index]-energy[index-1]);
    int secondJump = INT_MAX;
    if(index-2 >= 0)
        secondJump = getMinimumEnergyTopDown(energy, dp, index-2) + abs(energy[index]-energy[index-2]);

    return dp[index] = min(firstJump, secondJump);
}

// Convert a memoisation to a bottom up.
int getMinimumEnergyBottomUp(vector<int>& energy, int n) {

    vector<int> dp(n, 0);
    
    dp[0] = 0;
    for(int i=1; i<n; ++i) {
        int fj = dp[i-1] + abs(energy[i]-energy[i-1]);
        int sj = INT_MAX;
        if(i > 1)   sj = dp[i-2] + abs(energy[i]-energy[i-2]);
        dp[i] = min(fj, sj);
    }
    return dp[n-1];
}

int main() {

    vector<int> energy = {30, 10, 60, 10, 60, 50};
    int n = energy.size();
    vector<int> dp(n, -1);

    cout << "Recurance : " << getMinimumEnergy(energy, n-1) << endl;
    cout << "Memoisation : " << getMinimumEnergyTopDown(energy, dp, n-1) << endl;
    cout << "Bottom-Up : " << getMinimumEnergyBottomUp(energy, n) << endl;

    return 0;
}