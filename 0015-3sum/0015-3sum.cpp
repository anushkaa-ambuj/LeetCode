class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Sort Array
        sort(nums.begin(), nums.end());

        for (int i=0;i<n-2;i++){
            // Skip duplicates for the current number to avoid repeated triplets
            if (i>0 && nums[i]==nums[i-1]) continue;

            int left=i+1, right=n-1;

            while (left<right){
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the left pointer
                    while (left<right && nums[left]==nums[left+1]) left++;
                    // Skip duplicates for the right pointer
                    while (left<right && nums[right]==nums[right-1]) right--;

                    left++;
                    right--;
                }

                else if (sum>0){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return ans;
    }
};