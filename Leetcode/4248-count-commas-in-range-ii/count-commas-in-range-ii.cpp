class Solution {
public:
    long long countCommas(long long n) {
        long long start = 10;
        long long ans = 0;
        for (int i = 1; i <= 15; ++i) {
            long long end = min(n, (start * 10) - 1);
            ans += max(0LL, end - start + 1) * (i / 3);
            start *= 10;
        }
        return ans;
    }
};