class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(candidates, 0, target, ans, ds);
        return ans;
    }

private: 
    void findCombinations(vector<int>& arr, int index, int target, vector<vector<int>> &ans, vector<int> &ds){
        if (target==0){
            ans.push_back(ds);
            return;
        }

        for (int i=index; i<arr.size();i++){
            if (i>index && arr[i]==arr[i-1]) continue;
            if (arr[i]>target) break;

            ds.push_back(arr[i]);
            findCombinations(arr, i+1, target-arr[i], ans, ds);
            ds.pop_back();
        }
    }

};