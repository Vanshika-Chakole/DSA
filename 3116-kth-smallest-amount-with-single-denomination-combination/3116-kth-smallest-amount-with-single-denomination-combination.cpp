class Solution {
public:

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countWays(long long x, vector<int>& coins) {

        int n = coins.size();
        long long count = 0;

        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;
            bool tooBig = false;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    L = lcm(L, coins[i]);

                    if (L > x) {
                        tooBig = true;
                        break;
                    }
                }
            }

            if (tooBig)
                continue;

            long long cur = x / L;

            if (bits % 2 == 1)
                count += cur;
            else
                count -= cur;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countWays(mid, coins) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};