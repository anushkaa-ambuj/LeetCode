class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int mini = n/3 + 1;

        unordered_map<int,int> freq;

        for(int i=0;i<n;i++){
            freq[nums[i]] += 1;

            if (freq[nums[i]] == mini){
                ans.push_back(nums[i]);
            }

            if (ans.size() == 2) break;
        }

        return ans;
    }
};