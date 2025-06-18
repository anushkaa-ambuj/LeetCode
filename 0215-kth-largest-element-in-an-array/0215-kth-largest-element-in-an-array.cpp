class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); //Time: O(nlogn)

        return nums[nums.size()-k];
    }
};