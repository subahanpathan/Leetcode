class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine the sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Use long long to safely handle INT_MIN
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long quotient = 0;

        while (a >= b) {

            long long value = b;
            long long multiple = 1;

            // Double the divisor using bit shifting
            while ((value << 1) <= a) {
                value <<= 1;
                multiple <<= 1;
            }

            a -= value;
            quotient += multiple;
        }

        if (negative)
            quotient = -quotient;

        return (int)quotient;
    }
};