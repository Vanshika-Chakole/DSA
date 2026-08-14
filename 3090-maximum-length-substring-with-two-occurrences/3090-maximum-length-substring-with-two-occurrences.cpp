class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int, int> f;

        int l = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            f[s[i]]++;

        while(f[s[i]] > 2) {
            f[s[l]]--;
            l++;
        }
       ans = max(ans, i - l + 1);
    }
    return ans;
    }
};