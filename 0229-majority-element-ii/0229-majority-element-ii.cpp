class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int req_count = n/3;

        for (int i=0;i<n;i++){
            if (ans.size() == 0 || nums[i] != ans[0]){
                int count = 1;
                for (int j=i+1; j<n; j++){
                    if(nums[j]==nums[i]){
                        count++;
                    }
                }  

                if(count>req_count){
                    ans.push_back(nums[i]);
                }
            }

            if(ans.size()==2) break;
        }

        return ans;
    }
};