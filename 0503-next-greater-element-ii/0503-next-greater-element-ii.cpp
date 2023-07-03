class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector < int > nge(n, -1);
        stack < int > st;
        
        // Note: We perform the circular array variant similar to the linear variant question. 
        // Modify the iteration n-1 -> 2n-1; insert i -> i%n
        for (int i = 2*n - 1; i >= 0; i--) {
            // Remove all the elements smaller than the element from the stack
            while (!st.empty() && st.top() <= nums[i % n]) {
              st.pop();
            }
            
            // Inserts the next greatest element into the array present in the stack
            if (i < n) {
              if (!st.empty()) 
                  nge[i] = st.top();
            }
            // else inserts -1
            
            // Push the element into the stack
            st.push(nums[i % n]);
        }
        return nge;   
    }
};