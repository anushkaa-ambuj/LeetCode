class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        if (n<=1) return s;

        int l=0, r=n-1;
        while(l<r){
            // If both are vowels
            if (checkLetter(s[l]) && checkLetter(s[r])){
                swap(s[l], s[r]);
                l++;
                r--;
            }
            // If one is vowel, then find another
            else if(checkLetter(s[l])){
                r--;
            }
            else if(checkLetter(s[r])){
                l++;
            }
            // If both are not vowel
            else{
                l++;
                r--;
            }
        }
        return s;
    }
private:
    bool checkLetter(char c){
        if ( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ){
            return true;
        }
        return false;
    }
};