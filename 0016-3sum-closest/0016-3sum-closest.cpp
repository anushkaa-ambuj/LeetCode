class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();    
        sort(nums.begin(), nums.end());

        int min_diff = INT_MAX, ans;

        for (int i=0; i<n; i++){
            int j=i+1, k=n-1;
            while (j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if (min_diff > abs(target-sum)){
                    min_diff = abs(target-sum);
                    ans = sum;
                }
                else if (sum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};