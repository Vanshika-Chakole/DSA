class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = 0;
        for(int i = 0; i < nums.size(); i++){
            int x = 0;
            for(int j = i; j < nums.size(); j++){
                x = gcd(x, nums[j]);
                if(x == k){
                  n++;
                }
            }
        }
        return n;
    }
};
        