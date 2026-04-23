class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> un;

        for(int i = 0; i < n; i++){
            un[nums[i]].push_back(i);
        }

        vector<long long> x(n, 0);

        for(auto &p : un){
            auto &v = p.second;
            int  k = v.size();

            vector<long long> prefix(k, 0);
            prefix[0] = v[0];
        

        for(int i = 1; i < k; i++){
            prefix[i] = prefix[i - 1] + v[i];
        }

        for(int i = 0; i < k; i++){
            long long l = (long long)v[i] * i - (i > 0 ? prefix[i -1] : 0);
            long long r = (prefix[k - 1] - prefix[i] - (long long)v[i] * (k - i - 1));
            x[v[i]] = l + r;
        }
        }
        return x;
    }
};