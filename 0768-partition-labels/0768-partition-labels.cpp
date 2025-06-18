class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;

        // Step 1: Store last occurrence of each character
        vector<int> lastOccur(26);
        for (int i=0; i<s.length(); i++){
            lastOccur[s[i]-'a'] = i;
        }

        // Step 2: Greedy Partitioning
        int start=-1, end=0;
        for (int i=0; i<s.length(); i++){
            end = max(end, lastOccur[s[i]-'a']);
            if(end == i){
                ans.push_back(end-start);
                start = end;
            }
        }
        return ans;
    }
};