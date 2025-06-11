class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversed = 0;
        // Reverses only half // Most optimized
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // For even and odd digit numbers
        return (x == reversed || x == reversed / 10);
        //Explanation
        // Input | Final x | Final reversed |  Result
        //  121	 |    1	   |      12        |  (1 == 12 / 10)
        // 1221  |	 12	   |      12        |  (12 == 12)
    }
};