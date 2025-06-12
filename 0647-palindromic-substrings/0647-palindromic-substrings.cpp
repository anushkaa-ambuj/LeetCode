class Solution {
public:
    int checkPalindrome(string s, int left, int right){
        int count=0;

        while (left>=0 && right<s.length() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int ans=0;

        for(int i=0;i<s.length();i++){
            ans += checkPalindrome(s,i,i); //For odd length
            ans += checkPalindrome(s,i,i+1); //For even length
        }
        return ans;
    }
};