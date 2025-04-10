#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @leet start
class Solution {
   public:
    //和之前的滑动窗口是大同小异的，主要是记录连续字符相同的数量
    int longestSemiRepetitiveSubstring(string s) {
        //长度至少为1
        int ans = 1;
        int l = 0;
        int count_same = 0;
        for (int r = 1; r < s.size(); r++) {
            if (s[r] == s[r - 1]) {
                count_same++;
            }
            while (count_same >= 2) {
                if (s[l] == s[l + 1]) {
                    count_same--;
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// @leet end

int main() {

    return 0;
}
