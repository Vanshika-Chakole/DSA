class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(n + 1, m);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }

            suf[i] = j + 1;
        }

        vector<int> ans;

        j = 0;
        bool changed = false;

        for (int i = 0; i < n && j < m; i++) {

            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            else if (!changed) {

                int matchedAfter = m - suf[i + 1];

                if (j + 1 + matchedAfter >= m) {
                    ans.push_back(i);
                    j++;
                    changed = true;
                }
            }
        }
        if (j != m)
            return {};
        return ans;
    }
};