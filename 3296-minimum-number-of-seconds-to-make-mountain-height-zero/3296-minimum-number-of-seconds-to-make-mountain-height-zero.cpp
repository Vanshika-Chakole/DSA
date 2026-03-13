class Solution {
public:
long long maxH(long long time, int t){
    long long val = (2*time)/t;
    long long x = (sqrt(1+4*val) - 1) / 2;
    return x;
}
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0, high = 1e18;
        long long ans = high;
        while(low <= high){
            long long mid = (low + high) / 2;
            long long total = 0;
            for(int t : workerTimes){
                total += maxH(mid, t);
                if(total >= mountainHeight) break;
            }
        if(total >= mountainHeight){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
    }
};