class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        plaindromePartioning(s, 0, ans, ds);
        return ans;
    }

    void plaindromePartioning(string s, int index, vector<vector<string>> &ans, vector<string> &ds){
        if (index==s.size()){
            ans.push_back(ds);
            return;
        }

        for (int i=index;i<s.size();i++){
            if (isPalindrome(s, index, i)){
                ds.push_back(s.substr(index, i-index+1));
                plaindromePartioning(s, i+1, ans, ds);
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end){
        while (start<=end){
            if (s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
};