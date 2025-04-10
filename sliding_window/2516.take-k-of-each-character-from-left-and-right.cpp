#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @leet start
class Solution {
   public:
    int takeCharacters(string s, int k) {
        int cnt[3];
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int l = 0;
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            if (cnt[i] < k)
                return -1;
        }
        for (int r = 0; r < s.size(); r++) {
            cnt[s[r] - 'a']--;
            while (cnt[s[r] - 'a'] < k) {
                cnt[s[l] - 'a']++;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return s.size() - ans;
    }
};
// @leet end

int main() {

    return 0;
}
