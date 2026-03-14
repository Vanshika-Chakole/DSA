class Solution {
public:
int count = 0;
string ans = "";
void solve(int n, int k, string cur){
    if(cur.length() == n){
        count++;

        if(count == k){
            ans = cur;
        }
        return;
    }
    for(char c : {'a','b','c'}){
        if(cur.size() > 0 && cur.back() == c) continue;
        solve(n, k, cur + c);
        if(ans != "") return;
    }
}
    string getHappyString(int n, int k) {
        solve(n, k, "");
       return ans;
    }
};