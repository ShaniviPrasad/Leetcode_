class Solution {
public:
    int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b, a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0, sumEven=0;
        int odd=1, even=2;
        for (int i=0; i<n; i++) {
            sumOdd+=odd;
            sumEven+=even;
            odd+=2;
            even+=2;
        }
        return gcd(sumOdd, sumEven);
    }
};