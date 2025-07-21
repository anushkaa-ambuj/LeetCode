class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1;

        while(l<=h){
            int mid = l + (h-l)/2;

            if(nums[mid] == target) return mid;
            
            // Left Half is sorted
            if(nums[l] <= nums[mid]){
                if(nums[l]<=target && target<nums[mid]){
                    h = mid-1; // Search left
                }
                else{
                    l = mid+1; // Search right
                }
            }
            // Right Half is sorted
            else{
                if(nums[mid]<target && target<=nums[h]){
                    l = mid+1; // Search right
                }
                else{
                    h = mid-1; // Search left
                }
            }   
        }
        return -1;
    }
};