class Solution {
public:
    // Returns the length of palindrome centered at left and right
    int expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; // length of palindrome, since the pointers of palindrome are 'left+1' & 'right-1'
    }

    string longestPalindrome(const string &s) {
        if (s.empty()) return "";

        int start = 0, end = 0;

        for (int i = 0; i < s.size(); ++i) {
            int len1 = expandAroundCenter(s, i, i);     // odd-length
            int len2 = expandAroundCenter(s, i, i + 1); // even-length
            int len = max(len1, len2);

            if (len > end - start + 1) {
                // Update start and end using center and length
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};