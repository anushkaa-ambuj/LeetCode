class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if (s1.size() != s2.size()){
            return false;
        }

        unordered_map <char,int> charCount;
        for (char c:s1){
            charCount[c]++;
        }

        for (char c:s2){
            if (charCount.find(c) == charCount.end() || charCount[c]==0){
                return false;
            }
            charCount[c]--;
        }

        for (auto& q:charCount){
            if (q.second != 0){
                return false;
            }
        }

        return true;
    }
};