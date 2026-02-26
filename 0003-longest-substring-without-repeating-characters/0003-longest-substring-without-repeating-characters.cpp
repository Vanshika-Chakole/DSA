class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0, r = 0;
        int maxL = 0;
        while(r < s.length()){
            if(st.find(s[r]) == st.end()){
                st.insert(s[r]);
                maxL = max(maxL, r - l + 1);
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return maxL;
        
    }
};