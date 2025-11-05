class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int req_count = n/3;

        unordered_map<int,int> freq;

        for(int i=0;i<n;i++){
            freq[nums[i]] += 1;
        }

        for(auto&q:freq){
            if (q.second > req_count){
                ans.push_back(q.first);
            }
        }

        return ans;
    }
};