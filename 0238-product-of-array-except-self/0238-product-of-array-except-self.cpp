class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Initially, nums = {-1,2,0,4}
        //            ans = {1,1,1,1}

        // First pass: prefix products
        // ans = {1, -1, -2, 0}
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Second pass: suffix products
        // ans = {0,0,-8,0}
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
