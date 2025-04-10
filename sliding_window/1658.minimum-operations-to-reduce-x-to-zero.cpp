#include <limits.h>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

// @leet start
class Solution {
    //转换问题即可
   public:
    int minOperations(vector<int>& nums, int x) {
        int target = std::reduce(nums.begin(), nums.end(), 0) - x;
        if (target < 0) {
            return -1;
        }
        int cnt = 0;
        int l = 0;
        int ans = -1;
        for (int r = 0; r < nums.size(); r++) {
            cnt += nums[r];
            while (cnt > target) {
                cnt -= nums[l];
                l++;
            }
            if (cnt == target) {
                ans = max(ans, r - l + 1);
            }
        }
        return ans < 0 ? -1 : nums.size() - ans;
    }
};
// @leet end

int main() {

    return 0;
}
