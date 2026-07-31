// class Solution {
// public:

// const long long int lli;

// lli power( lli a, lli n){
//     if(n == 0) return 1;
//     lli x = power(a, n/2);
//     if(n % 2 == 1) return ((x%n * x % n) % n * a % mod) % n;
//     else retunr (x % n * x % n) % n;
// }
//     int countGoodNumbers(long long n) {
//         long long even = (n + 1) / 2;
//         long long odd = n / 2;
//     }
// };





class Solution {
public:
    using lli = long long;
    const lli mod = 1e9 + 7;

    lli power(lli a, lli n) {
        if (n == 0)
            return 1;

        lli x = power(a, n / 2);
        x = (x * x) % mod;

        if (n % 2 == 1)
            x = (x * a) % mod;

        return x;
    }

    int countGoodNumbers(long long n) {
        lli even = (n + 1) / 2;
        lli odd = n / 2;

        return (power(5, even) * power(4, odd)) % mod;
    }
};