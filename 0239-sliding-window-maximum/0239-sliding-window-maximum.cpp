class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Pair: {value, index}
        priority_queue<pair<int, int>> maxHeap;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Push current element with its index
            maxHeap.push({nums[i], i});

            // Remove elements outside the window
            while (maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }

            // Record answer when first window is ready
            if (i >= k - 1) {
                result.push_back(maxHeap.top().first);
            }
        }

        return result;
    }
};