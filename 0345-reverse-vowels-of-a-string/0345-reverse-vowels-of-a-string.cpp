class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        if (n<=1) return s;

        int l=0, r=n-1;
        while(l<r){
            // If both are vowels
            if (checkVowel(s[l]) && checkVowel(s[r])){
                swap(s[l], s[r]);
                l++;
                r--;
            }
            // If one is vowel, then find another
            else if(checkVowel(s[l])){
                r--;
            }
            else if(checkVowel(s[r])){
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
    bool checkVowel(char c){
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            return true;
        }
        return false;
    }
};