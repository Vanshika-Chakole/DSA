class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        for(int i = 0; i < n - 1; i++){
            if(s[i+1] == '1' && s[i] == '0'){
                    return false;
                 }
            }
            return true;
            
        }
};