#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void subSequences(int index, vector<int> &ans, vector<int> &nums) {
	
	if(index == nums.size()) {
		for(int x : ans)
			cout << x << " ";
		if(ans.size() == 0)
			cout << "{}";
		cout << endl;
		return;
	}
	// when we are pick this element of an array
	ans.push_back(nums[index]);
	subSequences(index+1, ans, nums);
	
	// remove that element that we are adding this ans when we pick this element
	ans.pop_back();
	
	// when we are pick this element of an array
	subSequences(index+1, ans, nums);
}

int main() {
	
	vector<int> nums = {3, 2, 4};
	vector<int> ans;
	subSequences(0, ans, nums);
	
	return 0;
}