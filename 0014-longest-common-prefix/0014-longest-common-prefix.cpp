class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int total_str = strs.size();
        string prefix = strs[0];

        if (strs.size() == 0){
            return "";
        }

        for (int i=1;i<strs.size();i++){
            while (strs[i].find(prefix) != 0){
                prefix = prefix.substr(0, prefix.length()-1);
                if (prefix.empty()){
                    return "";
                }
            }
        }
        return prefix;
    }
};