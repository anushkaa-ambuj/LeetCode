class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2,0);
        int i=0, j=numbers.size()-1;

        while(i<j){
            if (numbers[i] + numbers[j] == target){
                ans[0] = i+1;
                ans[1] = j+1;
                return ans;
            }

            else if (numbers[i] + numbers[j] > target){
                j--;
            }

            else{
                i++;
            }
        }
        return ans;
    }
};