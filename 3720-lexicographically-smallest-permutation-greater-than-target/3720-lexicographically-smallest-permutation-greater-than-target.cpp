class Solution {
public:
    string lexGreaterPermutation(
        string s, string target) {

        int n = s.size();

        // Frequency of characters in s
        int cnt[26] = {0};

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Build answer from left to right.
        // We first try to make prefix equal to target.
        string ans;

        for (int i = 0; i < n; i++) {

            // Try to put target[i]
            int x = target[i] - 'a';

            if (cnt[x] > 0) {

                ans.push_back(target[i]);
                cnt[x]--;

            } else {

                // target[i] is unavailable.
                // We need the smallest character greater than target[i].
                int bigger = -1;

                for (int c = x + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        bigger = c;
                        break;
                    }
                }

                if (bigger != -1) {

                    ans.push_back(char('a' + bigger));
                    cnt[bigger]--;

                    // Fill remaining positions with smallest chars
                    for (int c = 0; c < 26; c++) {
                        while (cnt[c] > 0) {
                            ans.push_back(char('a' + c));
                            cnt[c]--;
                        }
                    }

                    return ans;
                }

                // Cannot make answer greater at this position.
                // Need to go back and change an earlier position.
                break;
            }
        }

        // If we reached here, we either:
        // 1. made exactly target, or
        // 2. got stuck.
        //
        // Now find the rightmost position where we can
        // replace target[i] with a larger character.

        cnt[0] = 0;
        fill(cnt, cnt + 26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Try positions from right to left
        for (int i = n - 1; i >= 0; i--) {

            // We need characters used by target[0...i-1]
            // to be available.
            bool possible = true;

            int temp[26];
            for (int c = 0; c < 26; c++) {
                temp[c] = cnt[c];
            }

            for (int j = 0; j < i; j++) {

                int x = target[j] - 'a';

                if (temp[x] == 0) {
                    possible = false;
                    break;
                }

                temp[x]--;
            }

            if (!possible)
                continue;

            int x = target[i] - 'a';

            // Find smallest character > target[i]
            for (int c = x + 1; c < 26; c++) {

                if (temp[c] > 0) {

                    string res = target.substr(0, i);

                    res.push_back(char('a' + c));
                    temp[c]--;

                    // Remaining characters in sorted order
                    for (int ch = 0; ch < 26; ch++) {
                        while (temp[ch] > 0) {
                            res.push_back(char('a' + ch));
                            temp[ch]--;
                        }
                    }

                    return res;
                }
            }
        }

        return "";
    }
};