
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        long long total = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        long long k = (long long)k1 + k2;

        if (total <= k)
            return 0;

        int left = 0, right = mx;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long need = 0;

            for (int d : diff) {
                need += max(d - mid, 0);
            }

            if (need <= k)
                right = mid;
            else
                left = mid + 1;
        }

        long long ans = 0;

        for (int d : diff) {
            int remaining = min(d, left);
            ans += 1LL * remaining * remaining;
        }

        // Extra operations reduce some differences
        // from 'left' to 'left - 1'.
        long long used = 0;

        for (int d : diff) {
            used += max(d - left, 0);
        }

        long long extra = k - used;

        ans -= extra * (2LL * left - 1);

        return ans;
    }
};