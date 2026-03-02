class Solution {
    unordered_map<int, int> mp;
    int M;
public:
    Solution(int n, vector<int>& blacklist) {
        int b = blacklist.size();
        M = n - b;

        unordered_set<int> black(blacklist.begin(),blacklist.end());
        int last = n - 1;

        for(int b : blacklist){
            if(b < M){
                while(black.count(last)){
                last--;
            }
            mp[b] = last;
            last--;
        }
    }
    }
    int pick(){
        int r = rand() % M;
        if(mp.count(r)){
        return mp[r];
        }
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */