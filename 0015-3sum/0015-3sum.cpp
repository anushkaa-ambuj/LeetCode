class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++){
            int j=i+1, k=n-1;
            while (j<k){
                int sum = nums[i]+nums[j]+nums[k];
                int x = nums[j];
                int y = nums[k];

                if (sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
                else if (sum<0){
                    j++;
                }
                else{
                    k--;
                }

                while (j<k && nums[k]==y) k--;
                while (j<k && nums[j]==x) j++;
            }
        }
        return ans;
    }
};