#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @leet start
class Solution {
   public:
    // 题目的主要思路和水果成篮问题很类似，无非就是篮子数量不一样了
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        int left = 0;
        unordered_map<int, int> cnt_map;
        for (int right = 0; right < nums.size(); right++) {
            cnt_map[nums[right]]++;
            /*
            std::cout << "轮次: " << left << " " << right << " ";
            for (auto iter : cnt_map) {
                std::cout << "key: " << iter.first << " " << "value: " << iter.second << " ";
            }
            std::cout << std::endl;
            */
            std::cout << cnt_map[nums[right]] << std::endl;
            while (cnt_map[nums[right]] > k) {
                cnt_map[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @leet end

int main() {
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    Solution s;
    std::cout << s.maxSubarrayLength(nums, 2) << std::endl;
    return 0;
}
