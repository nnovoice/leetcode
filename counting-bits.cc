#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        int cnt = 0, t = 0, num_with_last_bit_set = 0;
        vector<int> res;
        for (int n = 0; n <= num; ++n) {
            cnt = 0;
            t = n;
            while (t != 0) {
                num_with_last_bit_set = t & ~(t - 1);
                if (num_with_last_bit_set != 0) cnt += 1;
                t -= num_with_last_bit_set;
            }
            res.push_back(cnt);
        }
        return res;
    }
};

int main() {
	Solution sol;
	vector<int> res = sol.countBits(10);
	vector<int> expected = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2};
	assert (res == expected);
	return 0;
}
