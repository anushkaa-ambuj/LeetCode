class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;

        // Next permutation will have longest prefix, we will find the break point
        for (int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }

        // Note: To handle the greatest permutation edge case; eg. [3 2 1]
        if (index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Substitute the nums[index] with the next bigger int
        // Iterate from back since, in decendingly sorted order
        for (int i=nums.size()-1; i>index; i--){
            if(nums[i] > nums[index]){
                // Swap, to maintain the order
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Now reverse the arr from index+1 to end, to get the smallest combination
        reverse(nums.begin() + index + 1, nums.end());
    }
};