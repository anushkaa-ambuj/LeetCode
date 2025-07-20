class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for(int num: numSet){
            // Only start counting if it's the start of a sequence
            if(!numSet.count(num-1)){
                int currNum = num;
                int streak = 1;

                while(numSet.count(currNum+1)){
                    currNum++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }
        return longest;
    }
};