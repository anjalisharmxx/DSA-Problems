class Solution {
public:
    long long sumAndMultiply(int n) {
        long long rev = 0, num = 0, sum = 0;

        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                rev = rev * 10 + d;
                sum += d;
            }
            n /= 10;
        }

        while (rev > 0) {
            num = num * 10 + rev % 10;
            rev /= 10;
        }

        return num * sum;
    }
};