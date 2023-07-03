class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map < int, int > mp;
        stack < int > st;
        
        int n = nums2.size();
        // Approach: Iterate the arr from the end 
        for (int i = n-1; i >= 0; i--) {
            // Remove all the elements smaller than the arr element from the stack
            while (!st.empty() && st.top() <= nums2[i]) {
              st.pop();
            }
            // Map the element to the req num.
            if (!st.empty()) 
                mp[nums2[i]] = st.top();
            // Push the element into the stack
            st.push(nums2[i]);
          }
        
          vector < int > res;
          for (int i = 0; i < nums1.size(); i++) {
            if (mp.find(nums1[i]) != mp.end()) 
                res.push_back(mp[nums1[i]]);
            else 
                res.push_back(-1);
          }
          return res;
    }
};