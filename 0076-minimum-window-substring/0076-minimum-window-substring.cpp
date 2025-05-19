class Solution {
public:
    string minWindow(string s, string t) {
        // Edge case: if s or t is empty or t is longer than s
        if (s.empty() || t.empty() || t.length() > s.length()) {
            return "";
        }

        // Count frequency of characters in t
        unordered_map<char, int> targetFreq;
        for (char i : t) {
            targetFreq[i]++;
        }
        int required = targetFreq.size(); // Number of unique characters to match

        unordered_map<char, int> windowFreq; // Current window character count
        int formed = 0;                      // Number of characters that meet the required frequency
        int l = 0, r = 0;                    // Sliding window pointers
        int minLen = INT_MAX;                // Length of the minimum window found
        int start = 0;                       // Start index of the minimum window

        while (r < s.size()) {
            // Expand the window to the right by including s[r]
            windowFreq[s[r]]++;

            // If current character completes its required frequency
            if (targetFreq.find(s[r]) != targetFreq.end() && windowFreq[s[r]] == targetFreq[s[r]]) {
                formed++;
            }

            // Try to contract the window until it's no longer valid
            while (l <= r && formed == required) {
                // Update the minimum window if smaller found
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Remove the leftmost character from the window
                char d = s[l];
                windowFreq[d]--;

                // If a required character goes below its needed count, reduce formed
                if (targetFreq.count(d) && windowFreq[d] < targetFreq[d]) {
                    formed--;
                }
                l++; // Shrink window from the left
            }

            r++; // Expand window to the right
        }

        // Return the minimum window or empty if not found
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};