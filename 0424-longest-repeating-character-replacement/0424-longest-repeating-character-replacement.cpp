class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int maxFreq = 0, maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);

            // If window size - maxFreq > k, it's invalid; shrink from left
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};