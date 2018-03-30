#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> counts;
        for (int i = 0; i < n; ++i)
            counts[nums[i]] += 1;
        for (int i = 0; i < n; ++i) {
            if (counts[nums[i]] > n/2) return nums[i];
        }
        return -1;
    }
};

int main() {
	Solution s;
	vector<int> nums = {1,2,1,2,1,2,1};
	int majorityElem = s.majorityElement(nums);
	return 0;
}
