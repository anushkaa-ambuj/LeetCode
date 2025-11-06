class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, h=nums.size()-1;

        while(l<h){
            int mid = l+(h-l)/2;

            if(nums[mid] > nums[mid+1]){
                // Peak is in left half including mid
                h = mid;
            }
            else{
                // Peak is right half
                l = mid+1;
            }
        }
        return l;
    }
};