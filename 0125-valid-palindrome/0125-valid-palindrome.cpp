class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (char c:s){
            if ((c>='a' && c<='z') || (c>='0' && c<='9')){
                t+=c;
            }
            else if ((c>='A' && c<='Z')){
                t+=(c+32);
            }
        }
        // cout<<t;
        
        int i=0, j=t.size()-1;
        while (i<=j){
            if (t[i] != t[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
};