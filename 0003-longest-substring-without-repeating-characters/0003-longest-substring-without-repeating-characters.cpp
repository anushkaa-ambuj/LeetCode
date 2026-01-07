class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s==""){
            return 0;
        }

        vector<int> freq(128,0);
        int len=s.size();
        int start=0, end=0, max_len=-1;

        while (end<len){
            freq[s[end]]++;

            if (freq[s[end]]>1){
                while (freq[s[end]]>1){
                    freq[s[start]]--;
                    start++;
                }
            }
            
            if (end-start+1 > max_len){
                max_len = end-start+1;
            }

            end++;
        }

        return max_len;
    }
};