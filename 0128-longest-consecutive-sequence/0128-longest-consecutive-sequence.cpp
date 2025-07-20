class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        int streak = 1;
        int longest = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                continue; //To handle duplicates
            }
            if(nums[i]==nums[i-1]+1){
                streak++;
            }
            else{
                longest = max(longest, streak);
                streak = 1;
            }
        }
        longest = max(longest, streak); //If it last streak is the longest
        return longest;
    }
};