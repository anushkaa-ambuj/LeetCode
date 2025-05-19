class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> contains;
        int length = 0;
        int l=0; int r=0;

        while (r < s.length()){
            while (contains.find(s[r]) != contains.end()){
                contains.erase(s[l]);
                l++;
            }
            contains.insert(s[r]);
            length = max(length, r-l+1);
            r++;
        }
        return length;
    }
};