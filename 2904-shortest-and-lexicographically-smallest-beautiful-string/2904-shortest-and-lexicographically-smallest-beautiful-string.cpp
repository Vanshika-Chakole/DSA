class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();

        int bestLen = INT_MAX;
        string ans = "";

        for (int i = 0; i < n; i++) {

            int ones = 0;

            for (int j = i; j < n; j++) {

                if (s[j] == '1') {
                    ones++;
                }

                // Exactly k ones
                if (ones == k) {

                    string cur = s.substr(i, j - i + 1);

                    // Smaller length
                    if (cur.length() < bestLen) {
                        bestLen = cur.length();
                        ans = cur;
                    }

                    // Same length but lexicographically smaller
                    else if (cur.length() == bestLen && cur < ans) {
                        ans = cur;
                    }

                    // Adding more characters will only increase
                    // the number of ones.
                    break;
                }

                // More than k ones -> this starting point
                // cannot give exactly k ones later.
                if (ones > k) {
                    break;
                }
            }
        }

        return ans;
    }
};