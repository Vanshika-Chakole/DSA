class Solution {
public:
    using ll = long long;

    const ll LIMIT = 1000000;

    // nCr with cap (we only need values up to k)
    ll nCr(int n, int r) {

        r = min(r, n - r);

        ll ans = 1;

        for (int i = 1; i <= r; i++) {

            ans = ans * (n - r + i) / i;

            if (ans >= LIMIT)
                return LIMIT;
        }

        return ans;
    }


    // count distinct permutations of half string
    ll countWays(vector<int>& cnt) {

        int total = 0;

        for (int x : cnt)
            total += x;


        ll ans = 1;


        for (int i = 0; i < 26; i++) {

            if (cnt[i] == 0)
                continue;


            // choose positions for this character
            ans *= nCr(total, cnt[i]);


            if (ans >= LIMIT)
                return LIMIT;


            total -= cnt[i];
        }


        return ans;
    }


    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);


        for (char c : s)
            freq[c - 'a']++;



        vector<int> half(26);

        string mid = "";


        for (int i = 0; i < 26; i++) {

            half[i] = freq[i] / 2;

            if (freq[i] % 2)
                mid += char('a' + i);
        }


        // check if kth palindrome exists
        if (countWays(half) < k)
            return "";



        string left = "";

        int len = s.size() / 2;



        // construct kth smallest half
        for (int pos = 0; pos < len; pos++) {


            for (int ch = 0; ch < 26; ch++) {


                if (half[ch] == 0)
                    continue;



                // try this character
                half[ch]--;


                ll ways = countWays(half);



                if (ways >= k) {

                    left += char('a' + ch);
                    break;

                }
                else {

                    k -= ways;
                    half[ch]++;

                }
            }
        }



        string right = left;

        reverse(right.begin(), right.end());


        return left + mid + right;
    }
};