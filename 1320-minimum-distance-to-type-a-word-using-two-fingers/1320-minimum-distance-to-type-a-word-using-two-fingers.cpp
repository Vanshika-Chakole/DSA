class Solution {
public:
    int getDist(char a, char b) {
        int x1 = (a - 'A') / 6, y1 = (a - 'A') % 6;
        int x2 = (b - 'A') / 6, y2 = (b - 'A') % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        
        // dp[finger position] = max saved distance
        vector<int> dp(26, 0);
        
        int total = 0;
        
        for (int i = 1; i < n; i++) {
            int dist = getDist(word[i-1], word[i]);
            total += dist;
            
            vector<int> new_dp(26, 0);
            
            for (int j = 0; j < 26; j++) {
                // move same finger → no saving
                new_dp[j] = max(new_dp[j], dp[j]);
                
                // move other finger
                int gain = dp[j] + dist - getDist('A' + j, word[i]);
                new_dp[word[i-1] - 'A'] = max(new_dp[word[i-1] - 'A'], gain);
            }
            
            dp = new_dp;
        }
        
        int maxSave = 0;
        for (int x : dp) maxSave = max(maxSave, x);
        
        return total - maxSave;
    }
};