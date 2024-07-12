class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findcombinationSum(candidates, 0, target, ans, ds);
        return ans;
    }

public:
    void findcombinationSum(vector<int>& arr, int index, int target, vector<vector<int>> &ans, vector<int> &ds) {
        if (index==arr.size()){
            if (target==0){
                ans.push_back(ds);
            }
            return;
        }

        if (arr[index]<=target){
            ds.push_back(arr[index]);
            findcombinationSum(arr, index, target-arr[index], ans, ds);
            ds.pop_back();
        }

        findcombinationSum(arr, index+1, target, ans, ds);
        
    }
};